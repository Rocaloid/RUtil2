#define _PitchToSPN _C(Tune_PitchToSPN, _, _T1)
#define _SPNToPitch _C(Tune_SPNToPitch, _, _T1)
#define _PitchToFreq _C(Tune_PitchToFreq, _, _T1)
#define _FreqToPitch _C(Tune_FreqToPitch, _, _T1)

RTFunc(_T1, Tune_PitchToSPN, _T1 Pitch, String* Dest);
RTFunc(_T1, Tune_SPNToPitch, String* SPN);

RTFunc(_T1, Tune_FreqToPitch, _T1 Freq);
RTFunc(_T1, Tune_PitchToFreq, _T1 Pitch);

// These functions are sugar.
RTFunc(_T1, Tune_FreqToSPN, _T1 Freq, String* Dest);
RTFunc(_T1, Tune_SPNToFreq, String* SPN);

#undef _FreqToPitch
#undef _PitchToSPN
#undef _SPNToPitch
#undef _PitchToFreq