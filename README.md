# AL_HW7

## 程式內容

撰寫一個程式會對兩個 200 X 198 的矩陣做運算，我們定義這個運算，會將 A 的每一個 row 對 B 的每一個 row 做 dot 。之後輸出一個 200 X 1 的陣列

For Example:
A         B         ANS
1 2 3 4   1 2 1 2   146 = ( 1*1 + 2*2 + 3*1 + 4*2 ) + ( 1*4 + 2*1 + 3*1 + 4*1) + ......
4 1 3 1   4 1 1 1   122
8 9 2 1   2 6 2 5   281
5 6 7 8   6 6 9 8   374

然後分別利用 SIMD 和 沒有利用 SIMD 去比較兩個程式的效能

## 執行環境

processor	: 0
vendor_id	: GenuineIntel
cpu family	: 6
model		: 142
model name	: Intel(R) Core(TM) i7-8565U CPU @ 1.80GHz
...
flags		: fpu vme de pse tsc msr pae mce cx8 apic sep mtrr pge mca cmov pat pse36 clflush mmx fxsr sse sse2 ss syscall nx pdpe1gb rdtscp lm constant_tsc arch_perfmon nopl xtopology tsc_reliable nonstop_tsc cpuid pni pclmulqdq ssse3 fma cx16 pcid sse4_1 sse4_2 x2apic movbe popcnt tsc_deadline_timer aes xsave avx f16c rdrand hypervisor lahf_lm abm 3dnowprefetch cpuid_fault invpcid_single ssbd ibrs ibpb stibp ibrs_enhanced fsgsbase tsc_adjust bmi1 avx2 smep bmi2 invpcid rdseed adx smap clflushopt xsaveopt xsavec xsaves arat md_clear flush_l1d arch_capabilities
...

processor	: 1
vendor_id	: GenuineIntel
cpu family	: 6
model		: 142
model name	: Intel(R) Core(TM) i7-8565U CPU @ 1.80GHz
....
flags		: fpu vme de pse tsc msr pae mce cx8 apic sep mtrr pge mca cmov pat pse36 clflush mmx fxsr sse sse2 ss syscall nx pdpe1gb rdtscp lm constant_tsc arch_perfmon nopl xtopology tsc_reliable nonstop_tsc cpuid pni pclmulqdq ssse3 fma cx16 pcid sse4_1 sse4_2 x2apic movbe popcnt tsc_deadline_timer aes xsave avx f16c rdrand hypervisor lahf_lm abm 3dnowprefetch cpuid_fault invpcid_single ssbd ibrs ibpb stibp ibrs_enhanced fsgsbase tsc_adjust bmi1 avx2 smep bmi2 invpcid rdseed adx smap clflushopt xsaveopt xsavec xsaves arat md_clear flush_l1d arch_capabilities
....

## 執行時間
            |    no simd    |     simd
-------------------------------------------
read_time   | 0.027110 sec  | 0.030384 sec
-------------------------------------------
compute_time| 0.033513 sec  | 0.025881 sec
-------------------------------------------
output_time | 0.000215 sec  | 0.000393 sec

## 如何編譯

	gcc -msse4 -o hw7_simd hw7simd.c
	gcc -o hw7 hw7.c

## 如何執行

  直接執行編譯出來的 hw7 跟 hw7_simd

## 使用的指令
  
  _mm_add_pd : Add packed double-precision (64-bit) floating-point elements in a and b, and store the results in dst.
  _mm_mul_pd : Multiply packed double-precision (64-bit) floating-point elements in a and b, and store the results in dst.
  
