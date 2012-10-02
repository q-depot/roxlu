#ifndef ROXLU_BUTTONS_SERVERH
#define ROXLU_BUTTONS_SERVERH

#include <buttons/Types.h>
#include <buttons/Element.h>
#include <buttons/Slider.h>

#include <string>
#include <vector>
#include <deque>
#include <roxlu/Roxlu.h> 

namespace buttons {
	class Server;
	class ServerConnections;
	
	// Structure which is used to hold deserialized data for gui types
	enum CommandDataName {
		BDATA_SCHEME // scheme: following data contains gui definitions
		,BDATA_GUI // scheme: flag there comes a gui definition
		,BDATA_CHANGED // value change on client or server
		,BDATA_SLIDERF // contains slider float
		,BDATA_SLIDERI  // contains slider integer
	};

	struct CommandData {
		CommandData() 
			:element(NULL)
			,buttons(NULL)
			,sliderf(NULL)
			,sliderf_value(0.0f)
			,slideri_value(0)
			,buttons_id(0)
			,element_id(0)
		{
		}
		ButtonsBuffer buffer;
		CommandDataName name;
		Element* element;
		Buttons* buttons;
		Sliderf* sliderf;
		float sliderf_value;
		int slideri_value;
		unsigned int buttons_id;
		unsigned int element_id;
	};

	// Utils for creating buffers which are send from client <--> server
	class ClientServerUtils {
	public:
		ClientServerUtils();
		~ClientServerUtils();
		bool serializeOnValueChanged(const Buttons& buttons, const Element* target, ButtonsBuffer& result);
		bool deserializeOnValueChanged(ButtonsBuffer& buffer, CommandData& data, std::map<unsigned int, std::map<unsigned int, Element*> >& elements);
	};

	struct ServerCommand {
		ServerCommand(char name):name(name) {
		}

		void setData(const char* data, size_t len) {
			buffer.addBytes((char*)data,len);
		}

		char name;
		ButtonsBuffer buffer;
	};

	class ServerConnection {
	public:
		ServerConnection(Server& server, ServerConnections& connections, Socket clientSocket);
		~ServerConnection();
		void send(ServerCommand& cmd);
		bool send(const char* data, size_t len);
		void read();
		void parseReadBuffer();
	public:
		Server& server; // we use server.elements when parsing client data; could be thread buggy
	private:
		ServerConnections& connections;
		ButtonsBuffer read_buffer;
		Socket client;
		ClientServerUtils util;
	};

	class ServerConnections : public roxlu::Runnable {
	public:
		ServerConnections(Server& server);
		~ServerConnections();
		void start();
		void run(); // thread
		void addConnection(ServerConnection* con);
		void sendToAll(ButtonServerCommandName name, const char* buffer, size_t len);
		void sendToAll(ServerCommand& cmd);
		void addCommand(ServerCommand cmd);
		void removeConnection(ServerConnection* con);
	private:
		Server& server;
		roxlu::Thread thread;
		roxlu::Mutex mutex;
		std::vector<ServerConnection*> connections;
		std::deque<ServerCommand> commands;
		std::vector<ServerConnection*> remove_list;

	};

	class Server : public roxlu::Runnable, public ButtonsListener {
	public:
		Server(const std::string ip, int port);
		~Server();
		void start();
		void run();
		void update();
		void syncButtons(Buttons& buttons);
		void onEvent(ButtonsEventType event, const Buttons& buttons, const Element* target);
		void testSend();
		void addTask(CommandData cmd);
	private:
		void createButtonsScheme();
		void sendScheme(ServerConnection* con); // sends all information about the guis to the client so the client can rebuild it.
		
	private:
		Socket server_socket;
		roxlu::Thread thread;
		roxlu::Mutex mutex;
		ServerConnections connections;
		int port;
		std::string ip;
		std::vector<Buttons*> buttons_to_sync;
		ButtonsBuffer scheme; // description used to recreate the panels + buttons on the client side
		ClientServerUtils utils; // helper for client/server to generate buffers
		std::vector<CommandData> tasks; // list of received and parsed commands we need to handle (e.g. change gui values)
	public:
		std::map<unsigned int, std::map<unsigned int, buttons::Element*> > elements; // indexed by buttons-hash and element hash
	};

} // buttons
#endif