#ifndef ROXLU_BTOGGLEH
#define ROXLU_BTOGGLEH

#include <buttons/Types.h>
#include <buttons/Element.h>

namespace buttons {

class Toggle : public Element {
public:	
	Toggle(bool& val, const string& name);
	~Toggle();

	void generateStaticText();
	void updateTextPosition();
	void generateVertices(ButtonVertices& shapeVertices);
	
	void onMouseDown(int mx, int my);
	void onMouseUp(int mx, int my);
	void onMouseEnter(int mx, int my);
	void onMouseLeave(int mx, int my);	
	void onMouseClick(int mx, int my);
	
	void save(std::ofstream& ofs);
	void load(std::ifstream& ifs);
	bool canSave();
	
	Toggle& setColor(const float hue, float a = 1.0);
	void hide();
	void show();
	void setValue(bool v);

	bool& value;
	
	float toggle_off_color[4];
	float toggle_on_color[4];
	int label_dx;
	bool is_radio;
};

inline void Toggle::setValue(bool v) {
	value = v;
}

} // namespace buttons

#endif
