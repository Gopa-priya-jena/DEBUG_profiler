#pragma once

#include <FORMATTER/util.hpp>
#include <string_view>
namespace DEBUG_profiler {

constexpr std::string_view Ctrl_Key("^[");
constexpr std::string_view Octal("\033");
constexpr std::string_view Unicode("\u001b");
constexpr std::string_view Hexadecimal("\x1B");
constexpr std::string_view Decimal("27");
constexpr std::string_view CSI("\x9B");
constexpr std::string_view Foreground("38;2;");
constexpr std::string_view Background("48;2;");
// General ASCII Codes
constexpr std::string_view BEL("\x07"); //	Terminal bell
constexpr std::string_view BS("\x08");  //	Backspace
constexpr std::string_view HT("\x09");  //	Horizontal TAB
constexpr std::string_view LF("\x0A");  //	Linefeed (newline)
constexpr std::string_view VT("\x0B");  //	Vertical TAB
constexpr std::string_view FF("\x0C");  //	Formfeed (also: New page NP)
constexpr std::string_view CR("\x0D");  //	Carriage return
constexpr std::string_view ESC("\x1B"); //	Escape character
constexpr std::string_view DEL("\x7F"); //	Delete character
// Code Sequence
// Screen Modes
constexpr Custom_delimiters<"\x1B[=", "h"> screen_modes;
// 0	40 x 25 monochrome (text)
// 1	40 x 25 color (text)
// 2	80 x 25 monochrome (text)
// 3	80 x 25 color (text)
// 4	320 x 200 4-color (graphics)
// 5	320 x 200 monochrome (graphics)
// 6	640 x 200 monochrome (graphics)
// 7	Enables line wrapping
// 13	320 x 200 color (graphics)
// 14	640 x 200 color (16-color graphics)
// 15	640 x 350 monochrome (2-color graphics)
// 16	640 x 350 color (16-color graphics)
// 17	640 x 480 monochrome (2-color graphics)
// 18	640 x 480 color (16-color graphics)
// 19	320 x 200 color (256-color graphics)

// Private Modes
constexpr Custom_delimiters<"\x1B[?", "h"> privtae_modes_h;
constexpr Custom_delimiters<"\x1B[?", "l"> privtae_modes_l;

// 47h	save screen
// 1049h	enables the alternative buffer
// 25h	make cursor visible
// 47l	restore screen
// 1049l	disables the alternative buffer
// 25l	make cursor invisible
//

// color sequence
// 256 Colors

constexpr Custom_delimiters<"\x1B[38;5;", "m"> color_256_fg;
constexpr Custom_delimiters<"\x1B[48;5;", "m"> color_256_bg;

// RGB Colors
constexpr Custom_delimiters<"\x1B[38;2;", "m", ";"> color_rgb_fg;
constexpr Custom_delimiters<"\x1B[48;2;", "m", ";"> color_rgb_bg;

// Colors / Graphics Mode
constexpr std::string_view
    RESET_SEQ("\x1B[0m "); // reset all modes (styles and colors)

constexpr Custom_delimiters<"\x1B[1m", "\x1B[22m"> bold_mode;
//	set bold mode.
constexpr Custom_delimiters<"\x1B[2m", "\x1B[22m">
    faint_mode; //	set dim/faint mode.
constexpr Custom_delimiters<"\x1B[3m", "\x1B[23m">
    italic_mode; //	set italic mode.
constexpr Custom_delimiters<"\x1B[4m", "\x1B[24m">
    underline_mode; //	set underline mode.
constexpr Custom_delimiters<"\x1B[5m", "\x1B[25m">
    blinking_mode; //	set blinking mode
constexpr Custom_delimiters<"\x1B[7m", "\x1B[27m">
    reverse_mode; //	set inverse/reverse mode
constexpr Custom_delimiters<"\x1B[8m", "\x1B[28m">
    invisible_mode; //	set hidden/invisible mode
constexpr Custom_delimiters<"\x1B[9m", "\x1B[29m">
    strikethrough_mode; //	set strikethrough mode.
} // namespace DEBUG_profiler
