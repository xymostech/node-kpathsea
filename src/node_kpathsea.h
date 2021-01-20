#pragma once

#include <nan.h>
#include <kpathsea/kpathsea.h>

class Kpathsea : public Nan::ObjectWrap {
public:
    static NAN_MODULE_INIT(Initialize);

    enum FileFormatType {
        GF,
        PK,
        ANY_GLYPH,
        TFM,
        AFM,
        BASE,
        BIB,
        BST,
        CNF,
        DB,
        FMT,
        FONTMAP,
        MEM,
        MF,
        MFPOOL,
        MFT,
        MP,
        MPPOOL,
        MPSUPPORT,
        OCP,
        OFM,
        OPL,
        OTP,
        OVF,
        OVP,
        PICT,
        TEX,
        TEXDOC,
        TEXPOOL,
        TEXSOURCE,
        TEX_PS_HEADER,
        TROFF_FONT,
        TYPE1,
        VF,
        DVIPS_CONFIG,
        IST,
        TRUETYPE,
        TYPE42,
        WEB2C,
        PROGRAM_TEXT,
        PROGRAM_BINARY,
        MISCFONTS,
        WEB,
        CWEB,
        ENC,
        CMAP,
        SFD,
        OPENTYPE,
        PDFTEX_CONFIG,
        LIG,
        TEXMFSCRIPTS,
        LUA,
        FEA,
        CID,
        MLBIB,
        MLBST,
        CLUA,
        RIS,
        BLTXML,
    };

private:
    Kpathsea(const char* progname);
    ~Kpathsea();

    static Nan::Persistent<v8::Function> constructor;
    static NAN_METHOD(New);

    static NAN_METHOD(FindFile);

    kpathsea innerKpse;
};
