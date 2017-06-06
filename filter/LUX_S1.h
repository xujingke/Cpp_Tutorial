#ifndef LUX_S1_h
#define LUX_S1_h

//////////////////////////////////////////////////////////////////////////
//                                                                      //
// LUX_S1                                                             //
//                                                                      //
// Description of the pulse and its parameters                          //
//                                                                      //
//////////////////////////////////////////////////////////////////////////

#include <TObject.h>
#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TSelector.h>

class TDirectory;

class LUX_S1 : public TObject {
    
    /*
        Class to store pulse information. To be used with filter.C
     */

public:
    Int_t   index;                  // index of the pulses of the event Y
    
    Float_t area;                   // pulse_area_phe Y
    Float_t area_cor;               // xyz_corrected_pulse_area_all_phe Y
    Float_t area_z_cor;             // z_corrected_pulse_area_all_phe Y
    Float_t area_bot_cor;           // xyz_corrected_pulse_area_bot_phe Y
    Float_t area_bot_z_cor;         // z_corrected_pulse_area_bot_phe Y
    
    Float_t spiky;                  // uncorrected spike count Y
    Float_t spiky_cor;              // xyz-corrected and overlap-corrected spike
                                    // count (valid for s1 area < ~100 phe) Y
    Float_t spiky_z_cor;            // z-corrected and overlap-corrected spike
                                    // count (valid for s1 area < ~100 phe) Y
    
    Float_t xyz_correction;         // correction_s1_xyz_dependence Y
    Float_t z_correction;           // correction_s1_z_dependence Y
    Float_t xyz_bot_correction;     // correction_s1_xyz_dependence_bot Y
    Float_t z_bot_correction;       // correction_s1_z_dependence_bot Y
    
    Float_t peak_area_pmt26;        // raw peak area in PMT 26 Y
    Int_t   spikes_pmt26;           // raw spikes in PMT 26 Y
    Float_t max_peak_area;          // raw peak area from PMT with largest contribution to pulse area Y
    Int_t   max_peak_index;         // index of PMT (0 to 121) with largest contribution to pulse area Y

    Int_t   aft_t0_samples;         // Y
    Int_t   aft_t1_samples;         // Y
    Int_t   aft_t2_samples;         // Y
    Int_t   aft_tlx_samples;        // Y
    Int_t   aft_trx_samples;        // Y
    Int_t   pulse_start_samples;    //
    Int_t   pulse_end_samples;      //

    Float_t max_pulse_height;	    // pulse_height_phe_per_sample Y

    Float_t tb_asymmetry;           // Y
    Float_t tb_ratio;               // Y
    Float_t prompt_fraction;        // Y
    Float_t prompt_fraction_tlx;    // Y
    
    Int_t   partner;                // check for 2-fold-coinc. in partner PMTs Y
    Int_t   se_before;              // count of SE and S2(area<55phe) before S1 Y
    
public:
//    LUX_S1();
//    virtual ~LUX_S1();
    
    void    SetIndex(Int_t i)                   { index = i; }; // Y
    void    SetTime(Int_t i0, Int_t i1, Int_t i2, Int_t i3, Int_t i4) // Y
    {   aft_t0_samples = i0; aft_t1_samples = i1; aft_t2_samples = i2; aft_tlx_samples = i3; aft_trx_samples = i4; };
    void    SetStartEnd(Int_t a, Int_t b)       { pulse_start_samples = a; pulse_end_samples = b; }; // Y
    
    void    SetAreas(Float_t a, Float_t ac, Float_t abc, Float_t azc, Float_t abzc) // Y
    {   area = a; area_cor = ac; area_bot_cor = abc; area_z_cor = azc; area_bot_z_cor = abzc; };
    
    void    SetPMTChecks(Float_t a, Int_t b, Float_t c, Int_t d) // Y
    {   peak_area_pmt26 = a; spikes_pmt26 = b; max_peak_area = c; max_peak_index = d; };
    
    void    SetMaxHeight(Float_t a)             { max_pulse_height = a; }; // Y
    void    SetTBAsym(Float_t a)                { tb_asymmetry = a; }; // Y
    void    SetTBRatio(Float_t a)               { tb_ratio = a; }; // Y
    void    SetPFrac(Float_t a, Float_t b)      { prompt_fraction = a; prompt_fraction_tlx = b; }; // Y
    
    void    SetXYZCor(Float_t a, Float_t b)     { xyz_correction = a; xyz_bot_correction = b; }; // Y
    void    SetZCor(Float_t a, Float_t b)       { z_correction = a; z_bot_correction = b; }; // Y

    void    SetSpikes(Float_t a, Float_t ac, Float_t azc) // Y
    { spiky = a; spiky_cor = ac; spiky_z_cor = azc; };
    
    void    SetPartner(Int_t i)                 { partner = i; }; // Y
    void    SetSEbefore(Int_t i)                { se_before = i; }; // Y
    
    ClassDef(LUX_S1,1)  //S1 Pulse structure // must be used in Root
};

#endif

#ifdef LUX_S1_cxx


#endif  // #ifdef LUX_S1_cxx
