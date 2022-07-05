#pragma once
#include "../../sdk/interfaces/interfaces.h"
#include "fonts/roboto_medium.h"
#include <mutex>
#include "../../sdk/other/color/color.h"

class vec2_t;
class vec3_t;

class c_render
{
	std::mutex m_render_mutex{};

	static ImU32 get_u32(c_color color)
	{
		return ((color[3] & 0xff) << 24) + ((color[2] & 0xff) << 16) + ((color[1] & 0xff) << 8) + (color[0] & 0xff);
	}

public:
	struct font_data_t
	{
		ImFont* m_esp{};
		ImFont* m_logs{};
	}m_fonts{};

	void rect(float x1, float y1, float x2, float y2, c_color color, float thickness = 1.f, float rounding = 0.f) const;
	void rect_filled(float x1, float y1, float x2, float y2, c_color color) const;
	void circle_2d(vec3_t position, int point_count, float radius, c_color color) const;
	void circle_2d_filled(vec3_t position, int point_count, float radius, c_color color) const;
	void circle_3d(vec3_t position, int point_count, float radius, c_color color) const;
	void circle_3d_filled(const vec3_t& origin, float radius, c_color color) const;
	void line(float x1, float y1, float x2, float y2, c_color color, float thickness) const;
	void triangle(ImVec2 first, ImVec2 second, ImVec2 third, c_color color) const;
	void text(const ImFont* font, ImVec2 text_position, const std::string& text, c_color color, bool centered,
		bool outline = true,
		bool menu = false);
	void init();
	void begin() const;
	void end();
	void clear_draw_list();
	ImDrawList* render_scene();

	ImDrawList* m_draw_list_act{};
	ImDrawList* m_draw_list_rendering{};
	ImDrawList* m_draw_list{};
	ImDrawData m_draw_data{};
};

inline c_render g_render;