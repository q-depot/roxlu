#ifndef ROXLU_BUTTONS_PANELH
#define ROXLU_BUTTONS_PANELH


#include <string>
#include <vector>
#include <map>


#include <buttons/Types.h>
#include <buttons/Element.h>
#include <buttons/Slider.h>
#include <buttons/Toggle.h>
#include <buttons/Button.h>
#include <buttons/Radio.h>
#include <buttons/Spline.h>
#include <buttons/Color.h>
#include <buttons/Storage.h>

using std::string;
using std::vector;
using std::map;

using namespace roxlu;

namespace buttons {

class Panel : public ButtonsListener {
public:
	Panel(const string& defaultGuiName, int w, int h);
	~Panel();
	
	void update();
	void draw();
	
	Sliderf& addFloat(const string& label, float& value);
	ColorPicker& addColor(const string& label, float* value); 
	
	Buttons& addButtons(const string& title);
	
	void save();
	void load();
	
	void onMouseMoved(int mx, int my);
	void onMouseDown(int mx, int my);
	void onMouseUp(int mx, int my);
	
	Buttons& getButtons(const string& name);

	void step(); // open/close gui one by one	
	void select(const string& name);
	void setColor(const float hue, float a = 1.0);
		
	void onRedraw(Buttons& bt);
	
	int getContentHeight();
	void position();
	
	int content_y;
	int content_x;
	int content_h;
	int w;
	int h;
	int step_dx;
	
	vector<Buttons*> guis;
	Buttons* active_gui;
};



} // buttons

#endif