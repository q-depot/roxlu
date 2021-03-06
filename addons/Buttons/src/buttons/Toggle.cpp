#include <buttons/Toggle.h>
#include <buttons/Buttons.h>

namespace buttons {
	
Toggle::Toggle(bool& val, const string& name) 
	:value(val)
	,Element(BTYPE_TOGGLE, name)
	,label_dx(0)
{
	h = 20;
}

Toggle::~Toggle() {
}

void Toggle::generateStaticText() {
	label_dx = static_text->add(x+20, y+2, label, 0.9, 0.9, 0.9, 0.9);
}

void Toggle::updateTextPosition() {	
	static_text->setTextPosition(label_dx, x+20, y+2);
}

void Toggle::generateVertices(ButtonVertices& vd) { 
	buttons::createRect(vd, x, y, w, h, bg_top_color, bg_bottom_color);
	float* c = toggle_off_color;
	if(value) {
		c = toggle_on_color;
	}
	
	buttons::createRect(vd, x+5, y+5, 10, 10, c, c);
}

void Toggle::onMouseDown(int mx, int my) {
}

void Toggle::onMouseUp(int mx, int my) {
}

void Toggle::onMouseEnter(int mx, int my) {
	bg_top_color = col_bg_top_hover;
	bg_bottom_color = col_bg_bottom_hover;
	needsRedraw();
}

void Toggle::onMouseLeave(int mx, int my) {
	bg_top_color = col_bg_default;
	bg_bottom_color = col_bg_default;
	needsRedraw();
}

void Toggle::onMouseClick(int mx, int my) {
	value = !value;
	needsRedraw();
}

bool Toggle::canSave() {
	return true;
}

void Toggle::save(ofstream& ofs) {
	size_t data_size = sizeof(int);
	ofs.write((char*)&data_size, data_size);
	int data = (value) ? 1 : 0;
	ofs.write((char*)&data, sizeof(int));
}

void Toggle::load(std::ifstream& ifs) {
	int data = 0;
	ifs.read((char*)&data, sizeof(int));
	value = (data == 1);
	needsRedraw();
}

void Toggle::hide() {
	is_visible = false;
	static_text->setTextVisible(label_dx, false);
}

void Toggle::show() {
	is_visible = true;
	static_text->setTextVisible(label_dx, true);
}

Toggle& Toggle::setColor(const float hue, float a) {
	Element::setColor(hue,a);
	HSL_to_RGB(col_hue, col_sat, col_bright - 0.1,  &toggle_off_color[0], &toggle_off_color[1], &toggle_off_color[2]);
	HSL_to_RGB(col_hue, col_sat, col_bright + 0.4,  &toggle_on_color[0], &toggle_on_color[1], &toggle_on_color[2]);
	toggle_on_color[3] = a;
	toggle_off_color[3] = a;
	return *this;
}

} // namespace buttons