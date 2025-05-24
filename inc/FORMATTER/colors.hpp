
#pragma once
#include <FORMATTER/icons.hpp>
#include <FORMATTER/util.hpp>
#include <array>
namespace DEBUG_profiler {

// need to  space optimize
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
inline constexpr color DEFAULT_BG = {0, 0, 0};
inline constexpr color BLACK = {0, 0, 0}; // DEFAULT_BG;
inline constexpr color WHITE = {255, 255, 255};
inline constexpr color RED = {255, 0, 0};
inline constexpr color GREEN = {0, 255, 0};
inline constexpr color YELLOW = {255, 255, 0};
inline constexpr color BLUE = {0, 0, 255};
inline constexpr color CYAN = {0, 255, 255};
inline constexpr color GRAY = {128, 128, 128};
// other colors
inline constexpr color alice_blue = {240, 248, 255};
inline constexpr color antique_white = {250, 235, 215};
inline constexpr color aquamarine = {127, 255, 212};
inline constexpr color azure = {240, 255, 255};
inline constexpr color beige = {245, 245, 220};
inline constexpr color bisque = {255, 228, 196};
inline constexpr color blanched_almond = {255, 235, 205};
inline constexpr color blue_violet = {138, 43, 226};
inline constexpr color brown = {165, 42, 42};
inline constexpr color burlywood = {222, 184, 135};
inline constexpr color cadet_blue = {95, 158, 160};
inline constexpr color chartreuse = {127, 255, 0};
inline constexpr color chocolate = {210, 105, 30};
inline constexpr color coral = {255, 127, 80};
inline constexpr color cornflower_blue = {100, 149, 237};
inline constexpr color cornsilk = {255, 248, 220};
inline constexpr color crimson = {220, 20, 60};
inline constexpr color dodger_blue = {30, 144, 255};
inline constexpr color firebrick = {178, 34, 34};
inline constexpr color floral_white = {255, 250, 240};
inline constexpr color forest_green = {34, 139, 34};
inline constexpr color fuchsia = {255, 0, 255};
inline constexpr color gainsboro = {220, 220, 220};
inline constexpr color ghost_white = {248, 248, 255};
inline constexpr color gold = {255, 215, 0};
inline constexpr color goldenrod = {218, 165, 32};
inline constexpr color green_yellow = {173, 255, 47};
inline constexpr color honeydew = {240, 255, 240};
inline constexpr color hot_pink = {255, 105, 180};
inline constexpr color indian_red = {205, 92, 92};
inline constexpr color indigo = {75, 0, 130};
inline constexpr color ivory = {255, 255, 240};
inline constexpr color khaki = {240, 230, 140};
inline constexpr color lavender = {230, 230, 250};
inline constexpr color lavender_blush = {255, 240, 245};
inline constexpr color lawn_green = {124, 252, 0};
inline constexpr color lemon_chiffon = {255, 250, 205};
inline constexpr color light_blue = {173, 216, 230};
inline constexpr color light_coral = {240, 128, 128};
inline constexpr color light_cyan = {224, 255, 255};
inline constexpr color light_goldenrod_yellow = {250, 250, 210};
inline constexpr color light_gray = {211, 211, 211};
inline constexpr color light_green = {144, 238, 144};
inline constexpr color light_pink = {255, 182, 193};
inline constexpr color light_salmon = {255, 160, 122};
inline constexpr color light_sea_green = {32, 178, 170};
inline constexpr color light_sky_blue = {135, 206, 250};
inline constexpr color light_slate_gray = {119, 136, 153};
inline constexpr color light_steel_blue = {176, 196, 222};
inline constexpr color light_yellow = {255, 255, 224};
inline constexpr color lime = {0, 255, 0};
inline constexpr color lime_green = {50, 205, 50};
inline constexpr color linen = {250, 240, 230};
inline constexpr color maroon = {128, 0, 0};
inline constexpr color medium_aquamarine = {102, 205, 170};
inline constexpr color medium_blue = {0, 0, 205};
inline constexpr color medium_orchid = {186, 85, 211};
inline constexpr color medium_purple = {147, 112, 219};
inline constexpr color medium_sea_green = {60, 179, 113};
inline constexpr color medium_slate_blue = {123, 104, 238};
inline constexpr color medium_spring_green = {0, 250, 154};
inline constexpr color medium_turquoise = {72, 209, 204};
inline constexpr color medium_violet_red = {199, 21, 133};
inline constexpr color midnight_blue = {25, 25, 112};
inline constexpr color mint_cream = {245, 255, 250};
inline constexpr color misty_rose = {255, 228, 225};
inline constexpr color moccasin = {255, 228, 181};
inline constexpr color navajo_white = {255, 222, 173};
inline constexpr color navy = {0, 0, 128};
inline constexpr color old_lace = {253, 245, 230};
inline constexpr color olive = {128, 128, 0};
inline constexpr color olive_drab = {107, 142, 35};
inline constexpr color orange = {255, 165, 0};
inline constexpr color orange_red = {255, 69, 0};
inline constexpr color orchid = {218, 112, 214};
inline constexpr color pale_goldenrod = {238, 232, 170};
inline constexpr color pale_green = {152, 251, 152};
inline constexpr color pale_turquoise = {175, 238, 238};
inline constexpr color pale_violet_red = {219, 112, 147};
inline constexpr color papaya_whip = {255, 239, 213};
inline constexpr color peach_puff = {255, 218, 185};
inline constexpr color peru = {205, 133, 63};
inline constexpr color pink = {255, 192, 203};
inline constexpr color plum = {221, 160, 221};
inline constexpr color powder_blue = {176, 224, 230};
inline constexpr color purple = {128, 0, 128};
inline constexpr color rosy_brown = {188, 143, 143};
inline constexpr color royal_blue = {65, 105, 225};
inline constexpr color saddle_brown = {139, 69, 19};
inline constexpr color salmon = {250, 128, 114};
inline constexpr color sandy_brown = {244, 164, 96};
inline constexpr color sea_green = {46, 139, 87};
inline constexpr color seashell = {255, 245, 238};
inline constexpr color sienna = {160, 82, 45};
inline constexpr color silver = {192, 192, 192};
inline constexpr color sky_blue = {135, 206, 235};
inline constexpr color slate_blue = {106, 90, 205};
inline constexpr color slate_gray = {112, 128, 144};
inline constexpr color snow = {255, 250, 250};
inline constexpr color spring_green = {0, 255, 127};
inline constexpr color steel_blue = {70, 130, 180};
inline constexpr color tan_ = {210, 180, 140};
inline constexpr color teal = {0, 128, 128};
inline constexpr color THISTLE = {216, 191, 216};
inline constexpr color tomato = {255, 99, 71};
inline constexpr color turquoise = {64, 224, 208};
inline constexpr color violet = {238, 130, 238};
inline constexpr color wheat = {245, 222, 179};
inline constexpr color white_smoke = {245, 245, 245};
inline constexpr color Yellow_green = {154, 205, 50};
// dark colors
inline constexpr color dark_blue = {0, 0, 139};
inline constexpr color dark_cyan = {0, 139, 139};
inline constexpr color dark_goldenrod = {184, 134, 11};
inline constexpr color dark_gray = {169, 169, 169};
inline constexpr color dark_green = {0, 100, 0};
inline constexpr color dark_khaki = {189, 183, 107};
inline constexpr color dark_magenta = {139, 0, 139};
inline constexpr color dark_olive_green = {85, 107, 47};
inline constexpr color dark_orange = {255, 140, 0};
inline constexpr color dark_orchid = {153, 50, 204};
inline constexpr color dark_red = {139, 0, 0};
inline constexpr color dark_salmon = {233, 150, 122};
inline constexpr color dark_sea_green = {143, 188, 139};
inline constexpr color dark_slate_gray = {47, 79, 79};
inline constexpr color dark_turquoise = {0, 206, 209};
inline constexpr color dark_violet = {148, 0, 211};
inline constexpr color deep_pink = {255, 20, 147};
inline constexpr color deep_sky_blue = {0, 191, 255};
inline constexpr color dimgray = {105, 105, 105};

constexpr unsigned int RGB_start_ = 20;
inline constexpr std::array<const color *, 138> RGB_clrs_ = {
    &DEFAULT_BG,
    &BLACK,
    &WHITE,
    &RED,
    &GREEN,
    &YELLOW,
    &BLUE,
    &CYAN,
    &GRAY,
    &alice_blue,
    &antique_white,
    &aquamarine,
    &azure,
    &beige,
    &bisque,
    &blanched_almond,
    &blue_violet,
    &brown,
    &burlywood,
    &cadet_blue,
    &chartreuse,
    &chocolate,
    &coral,
    &cornflower_blue,
    &cornsilk,
    &crimson,
    &dodger_blue,
    &firebrick,
    &floral_white,
    &forest_green,
    &fuchsia,
    &gainsboro,
    &ghost_white,
    &gold,
    &goldenrod,
    &green_yellow,
    &honeydew,
    &hot_pink,
    &indian_red,
    &indigo,
    &ivory,
    &khaki,
    &lavender,
    &lavender_blush,
    &lawn_green,
    &lemon_chiffon,
    &light_blue,
    &light_coral,
    &light_cyan,
    &light_goldenrod_yellow,
    &light_gray,
    &light_green,
    &light_pink,
    &light_salmon,
    &light_sea_green,
    &light_sky_blue,
    &light_slate_gray,
    &light_steel_blue,
    &light_yellow,
    &lime,
    &lime_green,
    &linen,
    &maroon,
    &medium_aquamarine,
    &medium_blue,
    &medium_orchid,
    &medium_purple,
    &medium_sea_green,
    &medium_slate_blue,
    &medium_spring_green,
    &medium_turquoise,
    &medium_violet_red,
    &midnight_blue,
    &mint_cream,
    &misty_rose,
    &moccasin,
    &navajo_white,
    &navy,
    &old_lace,
    &olive,
    &olive_drab,
    &orange,
    &orange_red,
    &orchid,
    &pale_goldenrod,
    &pale_green,
    &pale_turquoise,
    &pale_violet_red,
    &papaya_whip,
    &peach_puff,
    &peru,
    &pink,
    &plum,
    &powder_blue,
    &purple,
    &rosy_brown,
    &royal_blue,
    &saddle_brown,
    &salmon,
    &sandy_brown,
    &sea_green,
    &seashell,
    &sienna,
    &silver,
    &sky_blue,
    &slate_blue,
    &slate_gray,
    &snow,
    &spring_green,
    &steel_blue,
    &tan_,
    &teal,
    &THISTLE,
    &tomato,
    &turquoise,
    &violet,
    &wheat,
    &white_smoke,
    &Yellow_green,
    &dark_blue,
    &dark_cyan,
    &dark_goldenrod,
    &dark_gray,
    &dark_green,
    &dark_khaki,
    &dark_magenta,
    &dark_olive_green,
    &dark_orange,
    &dark_orchid,
    &dark_red,
    &dark_salmon,
    &dark_sea_green,
    &dark_slate_gray,
    &dark_turquoise,
    &dark_violet,
    &deep_pink,
    &deep_sky_blue,
    &dimgray};
} // namespace DEBUG_profiler
