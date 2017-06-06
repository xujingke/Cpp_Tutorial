#ifndef LUX_S2_h
#define LUX_S2_h

//////////////////////////////////////////////////////////////////////////
//                                                                      //
// LUX_S2                                                               //
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

class LUX_S2 : public TObject {
    
    /*
        Class to store pulse information. To be used with filter.C
     */

public:
    
    Int_t   index;          // index of the pulses of the event Y
    
    Float_t area;           // pulse_area_phe (raw) Y
    Float_t area_cor;       // xyz_corrected_pulse_area_all_phe Y
    Float_t area_z_cor;     // z_corrected_pulse_area_all_phe Y
    Float_t area_bot_cor;   // xyz_corrected_pulse_area_bot_phe Y
    Float_t area_bot_z_cor; // z_corrected_pulse_area_bot_phe Y

    Float_t spiky;          // uncorrected spike count Y
    Float_t spiky_cor;      // xyz-corrected spike count (no overlap corr. for S2) Y
    Float_t spiky_z_cor;    // z-corrected spike count (no overlap corr. for S2) Y
    Float_t spiky_bot;      // uncorrected spike count -- bottom array only Y
    
    Float_t peak_area_pmt26;        // raw peak area in PMT 26 Y
    Int_t   spikes_pmt26;           // raw spikes in PMT 26 Y
    Float_t max_peak_area;          // raw peak area from PMT with largest contribution to pulse area Y
    Int_t   max_peak_index;         // index of PMT (0 to 121) with largest contribution to pulse area Y
    
    Float_t x_raw;          // Raw Mercury reconstruction Y
    Float_t y_raw;          // Y
    Float_t r_raw;          // Y
    Float_t x_delensed;     // Delensed (corrected) mercury reconstruction Y
    Float_t y_delensed;     // Y
    Float_t r_delensed;     // Y
    Float_t x_centroid;     // Raw positions from corrected centroid algorithm (probably terrible) Y
    Float_t y_centroid;     // Y
    Float_t r_centroid;     // Y
    Float_t x_taxy;         // Raw TAXY reconstruction Y
    Float_t y_taxy;         // Y
    Float_t r_taxy;         // Y
    
    Float_t chi2_rec;       // Mercury fit parameters Y
    UChar_t dof_rec;        // Y
    Float_t sdrad_sup;      // Y
    Float_t sdrad_inf;      // Y
    Float_t sdphi;          // Y
    
    Float_t drift;          // pulse_start[s1] to pulse_start[s2] Y
    Float_t drift_new;      // aft_t0[s1] to aft_t0[s2] Y
    
    Float_t xy_correction;  // correction_s2_xy_dependence Y
    Float_t z_correction;   // correction_s2_z_dependence Y
    
    Int_t   aft_t0_samples;         // Y
    Int_t   aft_t1_samples;         // Y
    Int_t   aft_t2_samples;         // Y
    Int_t   aft_tlx_samples;        // Y
    Int_t   aft_trx_samples;        // Y
    Int_t   hft_t0_samples;         // Y
    Int_t   hft_t1_samples;         // Y
    Int_t   hft_t2_samples;         // Y
    Int_t   pulse_start_samples;    // Y
    Int_t   pulse_end_samples;      // Y

    Float_t max_pulse_height;       // pulse_height_phe_per_sample Y
    Float_t rms_width_samples;      // Y
    Float_t gaus_fit_amp;           // Y
    Float_t gaus_fit_mu;            // Y
    Float_t gaus_fit_sigma;         // Y
    Float_t gaus_fit_chisq;         // Y
    Int_t   gaus_fit_dof;           // Y
    
    Float_t tb_asymmetry;           // Y
    Float_t tb_ratio;               // Y
    Float_t prompt_fraction;        // Y
    Float_t prompt_fraction_tlx;    // Y

    
public:
//    LUX_S2();
//    virtual ~LUX_S2();

    void    SetIndex(Int_t i)                   { index = i; }; // Y
    
    void    SetArea(Float_t a)                  { area = a; }; // Y
    void    SetAreaCor(Float_t a)               { area_cor = a; }; // Y
    void    SetAreaCorBot(Float_t a)            { area_bot_cor = a; }; // Y
    void    SetZCorAreas(Float_t a, Float_t b)  { area_z_cor = a; area_bot_z_cor = b; }; // Y
    
    void    SetSpiky(Float_t a)                 { spiky = a; }; // Y
    void    SetSpikyBot(Float_t a)              { spiky_bot = a; }; // Y
    void    SetSpikyCor(Float_t a)              { spiky_cor = a; }; // Y
    void    SetSpikyZCor(Float_t a)             { spiky_z_cor = a; }; // Y
    
    void    SetPMTChecks(Float_t a, Int_t b, Float_t c, Int_t d) // Y
    { peak_area_pmt26 = a; spikes_pmt26 = b; max_peak_area = c; max_peak_index = d; };
    
    void    SetPosRaw(Float_t x, Float_t y, Float_t rad) // Y
    {   x_raw = x; y_raw = y; r_raw = rad; };
    void    SetDelensed(Float_t x, Float_t y, Float_t rad) // Y
    {   x_delensed = x; y_delensed = y; r_delensed = rad; };
    void    SetPosCentroid(Float_t x, Float_t y, Float_t rad) // Y
    {   x_centroid = x; y_centroid = y; r_centroid = rad; };
    void    SetTaxy(Float_t x, Float_t y, Float_t rad) // Y
    {   x_taxy = x; y_taxy = y; r_taxy = rad; };
    
    void    SetMercury(Float_t q2, UChar_t dof, Float_t r_sup, Float_t r_inf, Float_t phi) // Y
    {   chi2_rec = q2; dof_rec = dof; sdrad_sup = r_sup; sdrad_inf = r_inf; sdphi = phi;};
    
    void    SetDrift(Float_t a)                 { drift = a; }; // Y
    void    SetDriftNew(Float_t a)              { drift_new = a; }; // Y
    
    void    SetXYZCor(Float_t a, Float_t b)     { xy_correction = a; z_correction = b; }; // Y
    
    void    SetAft(Int_t i0, Int_t i1, Int_t i2, Int_t i3, Int_t i4) // Y
    {   aft_t0_samples = i0; aft_t1_samples = i1; aft_t2_samples = i2; aft_tlx_samples = i3; aft_trx_samples = i4; };
    void    SetHft(Int_t i0, Int_t i1, Int_t i2) // Y
    {   hft_t0_samples = i0; hft_t1_samples = i1; hft_t2_samples = i2; }
    void    SetStartEnd(Int_t a, Int_t b)       { pulse_start_samples = a; pulse_end_samples = b; }; // Y
    
    void    SetMaxPulseHeight(Float_t a)        { max_pulse_height = a; }; // Y
    void    SetWidthRMS(Float_t a)              { rms_width_samples = a; }; // Y
    void    SetGausFit(Float_t a, Float_t m, Float_t s, Float_t q2, Int_t df) // Y
    { gaus_fit_amp = a; gaus_fit_mu = m; gaus_fit_sigma = s; gaus_fit_chisq = q2; gaus_fit_dof = df; }
    void    SetTBAsym(Float_t a)                { tb_asymmetry = a; }; // Y
    void    SetTBRatio(Float_t a)               { tb_ratio = a; }; // Y
    void    SetPFrac(Float_t a, Float_t b)      { prompt_fraction = a; prompt_fraction_tlx = b; }; // Y
    
    ClassDef(LUX_S2,1)  // S2 Pulse structure // must be used in Root
};

#endif

#ifdef LUX_S2_cxx


#endif  // #ifdef LUX_S2_cxx
