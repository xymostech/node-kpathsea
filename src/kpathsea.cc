#include "node_kpathsea.h"

Nan::Persistent<v8::Function> Kpathsea::constructor;


Kpathsea::Kpathsea(const char* progname) {
    innerKpse = kpathsea_new();
    kpathsea_set_program_name(innerKpse, progname, NULL);
}
Kpathsea::~Kpathsea() {
    kpathsea_finish(innerKpse);
    innerKpse = NULL;
}

NAN_MODULE_INIT(Kpathsea::Initialize) {
    v8::Local<v8::FunctionTemplate> tpl = Nan::New<v8::FunctionTemplate>(Kpathsea::New);
    tpl->SetClassName(Nan::New("Kpathsea").ToLocalChecked());
    tpl->InstanceTemplate()->SetInternalFieldCount(1);

    Nan::SetPrototypeMethod(tpl, "findFile", Kpathsea::FindFile);

    Kpathsea::constructor.Reset(tpl->GetFunction());
    Nan::Set(target, Nan::New("Kpathsea").ToLocalChecked(), tpl->GetFunction());

    v8::Local<v8::Object> formats = Nan::New<v8::Object>();
    Nan::Set(target, Nan::New("FILE_FORMAT").ToLocalChecked(), formats);

    Nan::Set(formats, Nan::New("GF").ToLocalChecked(), Nan::New<v8::Integer>(Kpathsea::FileFormatType::GF));
    Nan::Set(formats, Nan::New("PK").ToLocalChecked(), Nan::New<v8::Integer>(Kpathsea::FileFormatType::PK));
    Nan::Set(formats, Nan::New("ANY_GLYPH").ToLocalChecked(), Nan::New<v8::Integer>(Kpathsea::FileFormatType::ANY_GLYPH));
    Nan::Set(formats, Nan::New("TFM").ToLocalChecked(), Nan::New<v8::Integer>(Kpathsea::FileFormatType::TFM));
    Nan::Set(formats, Nan::New("AFM").ToLocalChecked(), Nan::New<v8::Integer>(Kpathsea::FileFormatType::AFM));
    Nan::Set(formats, Nan::New("BASE").ToLocalChecked(), Nan::New<v8::Integer>(Kpathsea::FileFormatType::BASE));
    Nan::Set(formats, Nan::New("BIB").ToLocalChecked(), Nan::New<v8::Integer>(Kpathsea::FileFormatType::BIB));
    Nan::Set(formats, Nan::New("BST").ToLocalChecked(), Nan::New<v8::Integer>(Kpathsea::FileFormatType::BST));
    Nan::Set(formats, Nan::New("CNF").ToLocalChecked(), Nan::New<v8::Integer>(Kpathsea::FileFormatType::CNF));
    Nan::Set(formats, Nan::New("DB").ToLocalChecked(), Nan::New<v8::Integer>(Kpathsea::FileFormatType::DB));
    Nan::Set(formats, Nan::New("FMT").ToLocalChecked(), Nan::New<v8::Integer>(Kpathsea::FileFormatType::FMT));
    Nan::Set(formats, Nan::New("FONTMAP").ToLocalChecked(), Nan::New<v8::Integer>(Kpathsea::FileFormatType::FONTMAP));
    Nan::Set(formats, Nan::New("MEM").ToLocalChecked(), Nan::New<v8::Integer>(Kpathsea::FileFormatType::MEM));
    Nan::Set(formats, Nan::New("MF").ToLocalChecked(), Nan::New<v8::Integer>(Kpathsea::FileFormatType::MF));
    Nan::Set(formats, Nan::New("MFPOOL").ToLocalChecked(), Nan::New<v8::Integer>(Kpathsea::FileFormatType::MFPOOL));
    Nan::Set(formats, Nan::New("MFT").ToLocalChecked(), Nan::New<v8::Integer>(Kpathsea::FileFormatType::MFT));
    Nan::Set(formats, Nan::New("MP").ToLocalChecked(), Nan::New<v8::Integer>(Kpathsea::FileFormatType::MP));
    Nan::Set(formats, Nan::New("MPPOOL").ToLocalChecked(), Nan::New<v8::Integer>(Kpathsea::FileFormatType::MPPOOL));
    Nan::Set(formats, Nan::New("MPSUPPORT").ToLocalChecked(), Nan::New<v8::Integer>(Kpathsea::FileFormatType::MPSUPPORT));
    Nan::Set(formats, Nan::New("OCP").ToLocalChecked(), Nan::New<v8::Integer>(Kpathsea::FileFormatType::OCP));
    Nan::Set(formats, Nan::New("OFM").ToLocalChecked(), Nan::New<v8::Integer>(Kpathsea::FileFormatType::OFM));
    Nan::Set(formats, Nan::New("OPL").ToLocalChecked(), Nan::New<v8::Integer>(Kpathsea::FileFormatType::OPL));
    Nan::Set(formats, Nan::New("OTP").ToLocalChecked(), Nan::New<v8::Integer>(Kpathsea::FileFormatType::OTP));
    Nan::Set(formats, Nan::New("OVF").ToLocalChecked(), Nan::New<v8::Integer>(Kpathsea::FileFormatType::OVF));
    Nan::Set(formats, Nan::New("OVP").ToLocalChecked(), Nan::New<v8::Integer>(Kpathsea::FileFormatType::OVP));
    Nan::Set(formats, Nan::New("PICT").ToLocalChecked(), Nan::New<v8::Integer>(Kpathsea::FileFormatType::PICT));
    Nan::Set(formats, Nan::New("TEX").ToLocalChecked(), Nan::New<v8::Integer>(Kpathsea::FileFormatType::TEX));
    Nan::Set(formats, Nan::New("TEXDOC").ToLocalChecked(), Nan::New<v8::Integer>(Kpathsea::FileFormatType::TEXDOC));
    Nan::Set(formats, Nan::New("TEXPOOL").ToLocalChecked(), Nan::New<v8::Integer>(Kpathsea::FileFormatType::TEXPOOL));
    Nan::Set(formats, Nan::New("TEXSOURCE").ToLocalChecked(), Nan::New<v8::Integer>(Kpathsea::FileFormatType::TEXSOURCE));
    Nan::Set(formats, Nan::New("TEX_PS_HEADER").ToLocalChecked(), Nan::New<v8::Integer>(Kpathsea::FileFormatType::TEX_PS_HEADER));
    Nan::Set(formats, Nan::New("TROFF_FONT").ToLocalChecked(), Nan::New<v8::Integer>(Kpathsea::FileFormatType::TROFF_FONT));
    Nan::Set(formats, Nan::New("TYPE1").ToLocalChecked(), Nan::New<v8::Integer>(Kpathsea::FileFormatType::TYPE1));
    Nan::Set(formats, Nan::New("VF").ToLocalChecked(), Nan::New<v8::Integer>(Kpathsea::FileFormatType::VF));
    Nan::Set(formats, Nan::New("DVIPS_CONFIG").ToLocalChecked(), Nan::New<v8::Integer>(Kpathsea::FileFormatType::DVIPS_CONFIG));
    Nan::Set(formats, Nan::New("IST").ToLocalChecked(), Nan::New<v8::Integer>(Kpathsea::FileFormatType::IST));
    Nan::Set(formats, Nan::New("TRUETYPE").ToLocalChecked(), Nan::New<v8::Integer>(Kpathsea::FileFormatType::TRUETYPE));
    Nan::Set(formats, Nan::New("TYPE42").ToLocalChecked(), Nan::New<v8::Integer>(Kpathsea::FileFormatType::TYPE42));
    Nan::Set(formats, Nan::New("WEB2C").ToLocalChecked(), Nan::New<v8::Integer>(Kpathsea::FileFormatType::WEB2C));
    Nan::Set(formats, Nan::New("PROGRAM_TEXT").ToLocalChecked(), Nan::New<v8::Integer>(Kpathsea::FileFormatType::PROGRAM_TEXT));
    Nan::Set(formats, Nan::New("PROGRAM_BINARY").ToLocalChecked(), Nan::New<v8::Integer>(Kpathsea::FileFormatType::PROGRAM_BINARY));
    Nan::Set(formats, Nan::New("MISCFONTS").ToLocalChecked(), Nan::New<v8::Integer>(Kpathsea::FileFormatType::MISCFONTS));
    Nan::Set(formats, Nan::New("WEB").ToLocalChecked(), Nan::New<v8::Integer>(Kpathsea::FileFormatType::WEB));
    Nan::Set(formats, Nan::New("CWEB").ToLocalChecked(), Nan::New<v8::Integer>(Kpathsea::FileFormatType::CWEB));
    Nan::Set(formats, Nan::New("ENC").ToLocalChecked(), Nan::New<v8::Integer>(Kpathsea::FileFormatType::ENC));
    Nan::Set(formats, Nan::New("CMAP").ToLocalChecked(), Nan::New<v8::Integer>(Kpathsea::FileFormatType::CMAP));
    Nan::Set(formats, Nan::New("SFD").ToLocalChecked(), Nan::New<v8::Integer>(Kpathsea::FileFormatType::SFD));
    Nan::Set(formats, Nan::New("OPENTYPE").ToLocalChecked(), Nan::New<v8::Integer>(Kpathsea::FileFormatType::OPENTYPE));
    Nan::Set(formats, Nan::New("PDFTEX_CONFIG").ToLocalChecked(), Nan::New<v8::Integer>(Kpathsea::FileFormatType::PDFTEX_CONFIG));
    Nan::Set(formats, Nan::New("LIG").ToLocalChecked(), Nan::New<v8::Integer>(Kpathsea::FileFormatType::LIG));
    Nan::Set(formats, Nan::New("TEXMFSCRIPTS").ToLocalChecked(), Nan::New<v8::Integer>(Kpathsea::FileFormatType::TEXMFSCRIPTS));
    Nan::Set(formats, Nan::New("LUA").ToLocalChecked(), Nan::New<v8::Integer>(Kpathsea::FileFormatType::LUA));
    Nan::Set(formats, Nan::New("FEA").ToLocalChecked(), Nan::New<v8::Integer>(Kpathsea::FileFormatType::FEA));
    Nan::Set(formats, Nan::New("CID").ToLocalChecked(), Nan::New<v8::Integer>(Kpathsea::FileFormatType::CID));
    Nan::Set(formats, Nan::New("MLBIB").ToLocalChecked(), Nan::New<v8::Integer>(Kpathsea::FileFormatType::MLBIB));
    Nan::Set(formats, Nan::New("MLBST").ToLocalChecked(), Nan::New<v8::Integer>(Kpathsea::FileFormatType::MLBST));
    Nan::Set(formats, Nan::New("CLUA").ToLocalChecked(), Nan::New<v8::Integer>(Kpathsea::FileFormatType::CLUA));
    Nan::Set(formats, Nan::New("RIS").ToLocalChecked(), Nan::New<v8::Integer>(Kpathsea::FileFormatType::RIS));
    Nan::Set(formats, Nan::New("BLTXML").ToLocalChecked(), Nan::New<v8::Integer>(Kpathsea::FileFormatType::BLTXML));
}

NAN_METHOD(Kpathsea::New) {
    if (!info.IsConstructCall()) {
        return Nan::ThrowTypeError("Use the new operator to construct the DataChannel.");
    }

    Nan::Utf8String s(info[0]);
    Kpathsea *kpse = new Kpathsea(*s);
    kpse->Wrap(info.This());

    info.GetReturnValue().Set(info.This());
}

NAN_METHOD(Kpathsea::FindFile) {
    Kpathsea *self = Nan::ObjectWrap::Unwrap<Kpathsea>(info.This());

    const char* searchTerm = *Nan::Utf8String(info[0]);
    enum FileFormatType fileType = (enum FileFormatType)info[1]->Int32Value();

    const char* result = kpathsea_find_file(
        self->innerKpse,
        searchTerm,
        (kpse_file_format_type)fileType,
        false);

    info.GetReturnValue().Set(Nan::New(result).ToLocalChecked());
}

NAN_MODULE_INIT(Initialize) {
    Kpathsea::Initialize(target);
}

NODE_MODULE(NODE_GYP_MODULE_NAME, Initialize);
