#include "Fonts.hpp"

HFONT WidgetFonts::Urbanist(int height, int weight = FW_NORMAL){
    return CreateFontW(
            height, 0, 0, 0, weight,
            FALSE, FALSE, FALSE,
            DEFAULT_CHARSET,
            OUT_DEFAULT_PRECIS,
            CLIP_DEFAULT_PRECIS,
            CLEARTYPE_QUALITY,
            VARIABLE_PITCH | FF_SWISS,
            L"Urbanist"
        );
}

HFONT WidgetFonts::Doto(int height, int weight = FW_NORMAL){
    return CreateFontW(
            height, 0, 0, 0, weight,
            FALSE, FALSE, FALSE,
            DEFAULT_CHARSET,
            OUT_DEFAULT_PRECIS,
            CLIP_DEFAULT_PRECIS,
            CLEARTYPE_QUALITY,
            VARIABLE_PITCH | FF_SWISS,
            L"Doto"
        );
}

HFONT WidgetFonts::KodeMono(int height, int weight = FW_NORMAL){
    return CreateFontW(
            height, 0, 0, 0, weight,
            FALSE, FALSE, FALSE,
            DEFAULT_CHARSET,
            OUT_DEFAULT_PRECIS,
            CLIP_DEFAULT_PRECIS,
            CLEARTYPE_QUALITY,
            VARIABLE_PITCH | FF_SWISS,
            L"Kode Mono"
        );
}
