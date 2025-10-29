#include "LHAPDF/LHAPDF.h"
#include "clhapdf.h"
#include <string>
#include <iostream>
#include <math.h>
using namespace std;

void print_lhapdf_exception(const exception& e) {
    cerr << "\033[1;31mLHAPDF Exception:\033[0m " << e.what() << endl;
}

extern "C" {

cPDFSet* getPDFSet(const char* setname) {
    try {
        LHAPDF::PDFSet& pdfset = LHAPDF::getPDFSet(string(setname));
        return reinterpret_cast<cPDFSet*>(&pdfset);
    } catch (const exception& e) {
        print_lhapdf_exception(e);
        return nullptr;
    }
}

const char* get_entry(cPDFSet* cpdfset, const char* key) {
    LHAPDF::PDFSet* pdfset = reinterpret_cast<LHAPDF::PDFSet*>(cpdfset);
    try {
        return pdfset->get_entry(string(key)).c_str();
    } catch (const exception& e) {
        print_lhapdf_exception(e);
        return nullptr;
    }
}

cPDF* mkPDF(const char* setname_nmem) {
    try {
        LHAPDF::PDF* pdf = LHAPDF::mkPDF(string(setname_nmem));
        return reinterpret_cast<cPDF*>(pdf);
    } catch (const exception& e) {
        print_lhapdf_exception(e);
        return nullptr;
    }
}
void rmPDF(cPDF* cpdf) {
    LHAPDF::PDF* pdf = reinterpret_cast<LHAPDF::PDF*>(cpdf);
    delete pdf;
}

double alphasQ2(cPDF* cpdf, double Q2) {
    LHAPDF::PDF* pdf = reinterpret_cast<LHAPDF::PDF*>(cpdf);
    try {
        return pdf->alphasQ2(Q2);
    } catch (const exception& e) {
        print_lhapdf_exception(e);
        return NAN;
    }
}
double xfxQ2(cPDF* cpdf, int pid, double x, double Q2) {
    LHAPDF::PDF* pdf = reinterpret_cast<LHAPDF::PDF*>(cpdf);
    try {
        return pdf->xfxQ2(pid, x, Q2);
    } catch (const exception& e) {
        print_lhapdf_exception(e);
        return NAN;
    }
}

} // extern "C"
