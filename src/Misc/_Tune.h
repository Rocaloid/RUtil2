#define _PitchToSPN _C(Tune_PitchToSPN, _, _T1)
#define _SPNToPitch _C(Tune_SPNToPitch, _, _T1)
#define _PitchToFreq _C(Tune_PitchToFreq, _, _T1)
#define _FreqToPitch _C(Tune_FreqToPitch, _, _T1)

/* 音高数值 与 科学音高记号法的String 互转 */
RTFunc(_T1, Tune_PitchToSPN, _T1 Pitch, String* Dest);
RTFunc(_T1, Tune_SPNToPitch, String* SPN);

/* 频率数值 与 音高数值 互转*/
RTFunc(_T1, Tune_FreqToPitch, _T1 Freq);
RTFunc(_T1, Tune_PitchToFreq, _T1 Pitch);

/* 返回 Freq 增加 Cent 音分的偏移后的频率 */
RTFunc(_T1, Tune_AddCentToFreq, _T1 Freq, _T1 Cent);

/* 返回 Freq1 与 Freq2 之间相差的音高（单位：音分） */
RTFunc(_T1, Tune_CalcCentFromFreq, _T1 Freq1, _T1 Freq2);

/* 拍数和BPM 与 秒 互转 */
// Time unit is sec.
RTFunc(_T1, Tune_BeatToTime, _T1 BPM, _T1 BeatCnt);
RTFunc(_T1, Tune_TimeToBeat, _T1 BPM, _T1 Time);

/* 频率 与 科学音高记号法的String 互转 */
// These functions are sugar.
RTFunc(_T1, Tune_FreqToSPN, _T1 Freq, String* Dest);
RTFunc(_T1, Tune_SPNToFreq, String* SPN);

#undef _FreqToPitch
#undef _PitchToSPN
#undef _SPNToPitch
#undef _PitchToFreq
