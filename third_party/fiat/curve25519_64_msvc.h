/* Autogenerated: 'src/ExtractionOCaml/unsaturated_solinas' --inline --static --use-value-barrier --no-wide-int 25519 64 '(auto)' '2^255 - 19' carry_mul carry_square carry add sub opp selectznz to_bytes from_bytes relax carry_scmul121666 */
/* curve description: 25519 */
/* machine_wordsize = 64 (from "64") */
/* requested operations: carry_mul, carry_square, carry, add, sub, opp, selectznz, to_bytes, from_bytes, relax, carry_scmul121666 */
/* n = 5 (from "(auto)") */
/* s-c = 2^255 - [(1, 19)] (from "2^255 - 19") */
/* tight_bounds_multiplier = 1 (from "") */
/*  */
/* Computed values: */
/*   carry_chain = [0, 1, 2, 3, 4, 0, 1] */
/*   eval z = z[0] + (z[1] << 51) + (z[2] << 102) + (z[3] << 153) + (z[4] << 204) */
/*   bytes_eval z = z[0] + (z[1] << 8) + (z[2] << 16) + (z[3] << 24) + (z[4] << 32) + (z[5] << 40) + (z[6] << 48) + (z[7] << 56) + (z[8] << 64) + (z[9] << 72) + (z[10] << 80) + (z[11] << 88) + (z[12] << 96) + (z[13] << 104) + (z[14] << 112) + (z[15] << 120) + (z[16] << 128) + (z[17] << 136) + (z[18] << 144) + (z[19] << 152) + (z[20] << 160) + (z[21] << 168) + (z[22] << 176) + (z[23] << 184) + (z[24] << 192) + (z[25] << 200) + (z[26] << 208) + (z[27] << 216) + (z[28] << 224) + (z[29] << 232) + (z[30] << 240) + (z[31] << 248) */
/*   balance = [0xfffffffffffda, 0xffffffffffffe, 0xffffffffffffe, 0xffffffffffffe, 0xffffffffffffe] */

#include <stdint.h>
#include <intrin.h>
#if defined(_M_X64)
#include <immintrin.h>
#endif

typedef unsigned char fiat_25519_uint1;
typedef signed char fiat_25519_int1;

#define FIAT_25519_FIAT_INLINE inline

/* The type fiat_25519_loose_field_element is a field element with loose bounds. */
/* Bounds: [[0x0 ~> 0x18000000000000], [0x0 ~> 0x18000000000000], [0x0 ~> 0x18000000000000], [0x0 ~> 0x18000000000000], [0x0 ~> 0x18000000000000]] */
typedef uint64_t fiat_25519_loose_field_element[5];

/* The type fiat_25519_tight_field_element is a field element with tight bounds. */
/* Bounds: [[0x0 ~> 0x8000000000000], [0x0 ~> 0x8000000000000], [0x0 ~> 0x8000000000000], [0x0 ~> 0x8000000000000], [0x0 ~> 0x8000000000000]] */
typedef uint64_t fiat_25519_tight_field_element[5];

#if (-1 & 3) != 3
#error "This code only works on a two's complement system"
#endif

#define fiat_25519_value_barrier_u64(x) (x)

/*
 * The function fiat_25519_addcarryx_u64 is an addition with carry.
 *
 * Postconditions:
 *   out1 = (arg1 + arg2 + arg3) mod 2^64
 *   out2 = ⌊(arg1 + arg2 + arg3) / 2^64⌋
 *
 * Input Bounds:
 *   arg1: [0x0 ~> 0x1]
 *   arg2: [0x0 ~> 0xffffffffffffffff]
 *   arg3: [0x0 ~> 0xffffffffffffffff]
 * Output Bounds:
 *   out1: [0x0 ~> 0xffffffffffffffff]
 *   out2: [0x0 ~> 0x1]
 */
static FIAT_25519_FIAT_INLINE void fiat_25519_addcarryx_u64(uint64_t* out1, fiat_25519_uint1* out2, fiat_25519_uint1 arg1, uint64_t arg2, uint64_t arg3) {
// NOTE: edited after generation
#if defined(_M_X64)
  *out2 = _addcarry_u64(arg1, arg2, arg3, out1);
#else
  arg2 += arg1;
  arg1 = arg2 < arg1;
  arg3 += arg2;
  arg1 += arg3 < arg2;
  *out1 = arg3;
  *out2 = arg1;
#endif
}

/*
 * The function fiat_25519_subborrowx_u64 is a subtraction with borrow.
 *
 * Postconditions:
 *   out1 = (-arg1 + arg2 + -arg3) mod 2^64
 *   out2 = -⌊(-arg1 + arg2 + -arg3) / 2^64⌋
 *
 * Input Bounds:
 *   arg1: [0x0 ~> 0x1]
 *   arg2: [0x0 ~> 0xffffffffffffffff]
 *   arg3: [0x0 ~> 0xffffffffffffffff]
 * Output Bounds:
 *   out1: [0x0 ~> 0xffffffffffffffff]
 *   out2: [0x0 ~> 0x1]
 */
static FIAT_25519_FIAT_INLINE void fiat_25519_subborrowx_u64(uint64_t* out1, fiat_25519_uint1* out2, fiat_25519_uint1 arg1, uint64_t arg2, uint64_t arg3) {
#if defined(_M_X64)
  *out2 = _subborrow_u64(arg1, arg2, arg3, out1); // NOTE: edited after generation
#else
  *out1 = arg2 - arg3 - arg1;
  *out2 = (arg2 < arg3) | ((arg2 == arg3) & arg1);
#endif
}

/*
 * The function fiat_25519_addcarryx_u51 is an addition with carry.
 *
 * Postconditions:
 *   out1 = (arg1 + arg2 + arg3) mod 2^51
 *   out2 = ⌊(arg1 + arg2 + arg3) / 2^51⌋
 *
 * Input Bounds:
 *   arg1: [0x0 ~> 0x1]
 *   arg2: [0x0 ~> 0x7ffffffffffff]
 *   arg3: [0x0 ~> 0x7ffffffffffff]
 * Output Bounds:
 *   out1: [0x0 ~> 0x7ffffffffffff]
 *   out2: [0x0 ~> 0x1]
 */
static FIAT_25519_FIAT_INLINE void fiat_25519_addcarryx_u51(uint64_t* out1, fiat_25519_uint1* out2, fiat_25519_uint1 arg1, uint64_t arg2, uint64_t arg3) {
  uint64_t x1;
  uint64_t x2;
  fiat_25519_uint1 x3;
  x1 = ((arg1 + arg2) + arg3);
  x2 = (x1 & UINT64_C(0x7ffffffffffff));
  x3 = (fiat_25519_uint1)(x1 >> 51);
  *out1 = x2;
  *out2 = x3;
}

/*
 * The function fiat_25519_subborrowx_u51 is a subtraction with borrow.
 *
 * Postconditions:
 *   out1 = (-arg1 + arg2 + -arg3) mod 2^51
 *   out2 = -⌊(-arg1 + arg2 + -arg3) / 2^51⌋
 *
 * Input Bounds:
 *   arg1: [0x0 ~> 0x1]
 *   arg2: [0x0 ~> 0x7ffffffffffff]
 *   arg3: [0x0 ~> 0x7ffffffffffff]
 * Output Bounds:
 *   out1: [0x0 ~> 0x7ffffffffffff]
 *   out2: [0x0 ~> 0x1]
 */
static FIAT_25519_FIAT_INLINE void fiat_25519_subborrowx_u51(uint64_t* out1, fiat_25519_uint1* out2, fiat_25519_uint1 arg1, uint64_t arg2, uint64_t arg3) {
  int64_t x1;
  fiat_25519_int1 x2;
  uint64_t x3;
  x1 = ((int64_t)(arg2 - (int64_t)arg1) - (int64_t)arg3);
  x2 = (fiat_25519_int1)(x1 >> 51);
  x3 = (x1 & UINT64_C(0x7ffffffffffff));
  *out1 = x3;
  *out2 = (fiat_25519_uint1)(0x0 - x2);
}

/*
 * The function fiat_25519_mulx_u64 is a multiplication, returning the full double-width result.
 *
 * Postconditions:
 *   out1 = (arg1 * arg2) mod 2^64
 *   out2 = ⌊arg1 * arg2 / 2^64⌋
 *
 * Input Bounds:
 *   arg1: [0x0 ~> 0xffffffffffffffff]
 *   arg2: [0x0 ~> 0xffffffffffffffff]
 * Output Bounds:
 *   out1: [0x0 ~> 0xffffffffffffffff]
 *   out2: [0x0 ~> 0xffffffffffffffff]
 */
static FIAT_25519_FIAT_INLINE void fiat_25519_mulx_u64(uint64_t* out1, uint64_t* out2, uint64_t arg1, uint64_t arg2) {
// NOTE: edited after generation
#if defined(_M_X64)
  *out1 = _umul128(arg1, arg2, out2);
#elif defined(_M_ARM64)
  *out1 = arg1 * arg2;
  *out2 = __umulh(arg1, arg2);
#else
#error "This file is intended for MSVC on X64 or ARM64"
#endif
}

/*
 * The function fiat_25519_cmovznz_u64 is a single-word conditional move.
 *
 * Postconditions:
 *   out1 = (if arg1 = 0 then arg2 else arg3)
 *
 * Input Bounds:
 *   arg1: [0x0 ~> 0x1]
 *   arg2: [0x0 ~> 0xffffffffffffffff]
 *   arg3: [0x0 ~> 0xffffffffffffffff]
 * Output Bounds:
 *   out1: [0x0 ~> 0xffffffffffffffff]
 */
static FIAT_25519_FIAT_INLINE void fiat_25519_cmovznz_u64(uint64_t* out1, fiat_25519_uint1 arg1, uint64_t arg2, uint64_t arg3) {
  fiat_25519_uint1 x1;
  uint64_t x2;
  uint64_t x3;
  x1 = (!(!arg1));
  x2 = ((fiat_25519_int1)(0x0 - x1) & UINT64_C(0xffffffffffffffff));
  x3 = ((fiat_25519_value_barrier_u64(x2) & arg3) | (fiat_25519_value_barrier_u64((~x2)) & arg2));
  *out1 = x3;
}

/*
 * The function fiat_25519_carry_mul multiplies two field elements and reduces the result.
 *
 * Postconditions:
 *   eval out1 mod m = (eval arg1 * eval arg2) mod m
 *
 */
static FIAT_25519_FIAT_INLINE void fiat_25519_carry_mul(fiat_25519_tight_field_element out1, const fiat_25519_loose_field_element arg1, const fiat_25519_loose_field_element arg2) {
  uint64_t x1;
  uint64_t x2;
  uint64_t x3;
  uint64_t x4;
  uint64_t x5;
  uint64_t x6;
  uint64_t x7;
  uint64_t x8;
  uint64_t x9;
  uint64_t x10;
  uint64_t x11;
  uint64_t x12;
  uint64_t x13;
  uint64_t x14;
  uint64_t x15;
  uint64_t x16;
  uint64_t x17;
  uint64_t x18;
  uint64_t x19;
  uint64_t x20;
  uint64_t x21;
  uint64_t x22;
  uint64_t x23;
  uint64_t x24;
  uint64_t x25;
  uint64_t x26;
  uint64_t x27;
  uint64_t x28;
  uint64_t x29;
  uint64_t x30;
  uint64_t x31;
  uint64_t x32;
  uint64_t x33;
  uint64_t x34;
  uint64_t x35;
  uint64_t x36;
  uint64_t x37;
  uint64_t x38;
  uint64_t x39;
  uint64_t x40;
  uint64_t x41;
  uint64_t x42;
  uint64_t x43;
  uint64_t x44;
  uint64_t x45;
  uint64_t x46;
  uint64_t x47;
  uint64_t x48;
  uint64_t x49;
  uint64_t x50;
  uint64_t x51;
  fiat_25519_uint1 x52;
  uint64_t x53;
  fiat_25519_uint1 x54;
  uint64_t x55;
  fiat_25519_uint1 x56;
  uint64_t x57;
  fiat_25519_uint1 x58;
  uint64_t x59;
  fiat_25519_uint1 x60;
  uint64_t x61;
  fiat_25519_uint1 x62;
  uint64_t x63;
  fiat_25519_uint1 x64;
  uint64_t x65;
  fiat_25519_uint1 x66;
  uint64_t x67;
  uint64_t x68;
  uint64_t x69;
  fiat_25519_uint1 x70;
  uint64_t x71;
  fiat_25519_uint1 x72;
  uint64_t x73;
  fiat_25519_uint1 x74;
  uint64_t x75;
  fiat_25519_uint1 x76;
  uint64_t x77;
  fiat_25519_uint1 x78;
  uint64_t x79;
  fiat_25519_uint1 x80;
  uint64_t x81;
  fiat_25519_uint1 x82;
  uint64_t x83;
  fiat_25519_uint1 x84;
  uint64_t x85;
  fiat_25519_uint1 x86;
  uint64_t x87;
  fiat_25519_uint1 x88;
  uint64_t x89;
  fiat_25519_uint1 x90;
  uint64_t x91;
  fiat_25519_uint1 x92;
  uint64_t x93;
  fiat_25519_uint1 x94;
  uint64_t x95;
  fiat_25519_uint1 x96;
  uint64_t x97;
  fiat_25519_uint1 x98;
  uint64_t x99;
  fiat_25519_uint1 x100;
  uint64_t x101;
  fiat_25519_uint1 x102;
  uint64_t x103;
  fiat_25519_uint1 x104;
  uint64_t x105;
  fiat_25519_uint1 x106;
  uint64_t x107;
  fiat_25519_uint1 x108;
  uint64_t x109;
  fiat_25519_uint1 x110;
  uint64_t x111;
  fiat_25519_uint1 x112;
  uint64_t x113;
  fiat_25519_uint1 x114;
  uint64_t x115;
  fiat_25519_uint1 x116;
  uint64_t x117;
  fiat_25519_uint1 x118;
  uint64_t x119;
  fiat_25519_uint1 x120;
  uint64_t x121;
  fiat_25519_uint1 x122;
  uint64_t x123;
  fiat_25519_uint1 x124;
  uint64_t x125;
  fiat_25519_uint1 x126;
  uint64_t x127;
  fiat_25519_uint1 x128;
  uint64_t x129;
  fiat_25519_uint1 x130;
  uint64_t x131;
  fiat_25519_uint1 x132;
  uint64_t x133;
  fiat_25519_uint1 x134;
  uint64_t x135;
  uint64_t x136;
  uint64_t x137;
  uint64_t x138;
  fiat_25519_uint1 x139;
  uint64_t x140;
  uint64_t x141;
  uint64_t x142;
  uint64_t x143;
  fiat_25519_uint1 x144;
  uint64_t x145;
  uint64_t x146;
  uint64_t x147;
  uint64_t x148;
  fiat_25519_uint1 x149;
  uint64_t x150;
  uint64_t x151;
  uint64_t x152;
  uint64_t x153;
  uint64_t x154;
  uint64_t x155;
  uint64_t x156;
  uint64_t x157;
  fiat_25519_uint1 x158;
  uint64_t x159;
  uint64_t x160;
  fiat_25519_mulx_u64(&x1, &x2, (arg1[4]), ((arg2[4]) * UINT8_C(0x13)));
  fiat_25519_mulx_u64(&x3, &x4, (arg1[4]), ((arg2[3]) * UINT8_C(0x13)));
  fiat_25519_mulx_u64(&x5, &x6, (arg1[4]), ((arg2[2]) * UINT8_C(0x13)));
  fiat_25519_mulx_u64(&x7, &x8, (arg1[4]), ((arg2[1]) * UINT8_C(0x13)));
  fiat_25519_mulx_u64(&x9, &x10, (arg1[3]), ((arg2[4]) * UINT8_C(0x13)));
  fiat_25519_mulx_u64(&x11, &x12, (arg1[3]), ((arg2[3]) * UINT8_C(0x13)));
  fiat_25519_mulx_u64(&x13, &x14, (arg1[3]), ((arg2[2]) * UINT8_C(0x13)));
  fiat_25519_mulx_u64(&x15, &x16, (arg1[2]), ((arg2[4]) * UINT8_C(0x13)));
  fiat_25519_mulx_u64(&x17, &x18, (arg1[2]), ((arg2[3]) * UINT8_C(0x13)));
  fiat_25519_mulx_u64(&x19, &x20, (arg1[1]), ((arg2[4]) * UINT8_C(0x13)));
  fiat_25519_mulx_u64(&x21, &x22, (arg1[4]), (arg2[0]));
  fiat_25519_mulx_u64(&x23, &x24, (arg1[3]), (arg2[1]));
  fiat_25519_mulx_u64(&x25, &x26, (arg1[3]), (arg2[0]));
  fiat_25519_mulx_u64(&x27, &x28, (arg1[2]), (arg2[2]));
  fiat_25519_mulx_u64(&x29, &x30, (arg1[2]), (arg2[1]));
  fiat_25519_mulx_u64(&x31, &x32, (arg1[2]), (arg2[0]));
  fiat_25519_mulx_u64(&x33, &x34, (arg1[1]), (arg2[3]));
  fiat_25519_mulx_u64(&x35, &x36, (arg1[1]), (arg2[2]));
  fiat_25519_mulx_u64(&x37, &x38, (arg1[1]), (arg2[1]));
  fiat_25519_mulx_u64(&x39, &x40, (arg1[1]), (arg2[0]));
  fiat_25519_mulx_u64(&x41, &x42, (arg1[0]), (arg2[4]));
  fiat_25519_mulx_u64(&x43, &x44, (arg1[0]), (arg2[3]));
  fiat_25519_mulx_u64(&x45, &x46, (arg1[0]), (arg2[2]));
  fiat_25519_mulx_u64(&x47, &x48, (arg1[0]), (arg2[1]));
  fiat_25519_mulx_u64(&x49, &x50, (arg1[0]), (arg2[0]));
  fiat_25519_addcarryx_u64(&x51, &x52, 0x0, x13, x7);
  fiat_25519_addcarryx_u64(&x53, &x54, x52, x14, x8);
  fiat_25519_addcarryx_u64(&x55, &x56, 0x0, x17, x51);
  fiat_25519_addcarryx_u64(&x57, &x58, x56, x18, x53);
  fiat_25519_addcarryx_u64(&x59, &x60, 0x0, x19, x55);
  fiat_25519_addcarryx_u64(&x61, &x62, x60, x20, x57);
  fiat_25519_addcarryx_u64(&x63, &x64, 0x0, x49, x59);
  fiat_25519_addcarryx_u64(&x65, &x66, x64, x50, x61);
  x67 = ((x63 >> 51) | ((x65 << 13) & UINT64_C(0xffffffffffffffff)));
  x68 = (x63 & UINT64_C(0x7ffffffffffff));
  fiat_25519_addcarryx_u64(&x69, &x70, 0x0, x23, x21);
  fiat_25519_addcarryx_u64(&x71, &x72, x70, x24, x22);
  fiat_25519_addcarryx_u64(&x73, &x74, 0x0, x27, x69);
  fiat_25519_addcarryx_u64(&x75, &x76, x74, x28, x71);
  fiat_25519_addcarryx_u64(&x77, &x78, 0x0, x33, x73);
  fiat_25519_addcarryx_u64(&x79, &x80, x78, x34, x75);
  fiat_25519_addcarryx_u64(&x81, &x82, 0x0, x41, x77);
  fiat_25519_addcarryx_u64(&x83, &x84, x82, x42, x79);
  fiat_25519_addcarryx_u64(&x85, &x86, 0x0, x25, x1);
  fiat_25519_addcarryx_u64(&x87, &x88, x86, x26, x2);
  fiat_25519_addcarryx_u64(&x89, &x90, 0x0, x29, x85);
  fiat_25519_addcarryx_u64(&x91, &x92, x90, x30, x87);
  fiat_25519_addcarryx_u64(&x93, &x94, 0x0, x35, x89);
  fiat_25519_addcarryx_u64(&x95, &x96, x94, x36, x91);
  fiat_25519_addcarryx_u64(&x97, &x98, 0x0, x43, x93);
  fiat_25519_addcarryx_u64(&x99, &x100, x98, x44, x95);
  fiat_25519_addcarryx_u64(&x101, &x102, 0x0, x9, x3);
  fiat_25519_addcarryx_u64(&x103, &x104, x102, x10, x4);
  fiat_25519_addcarryx_u64(&x105, &x106, 0x0, x31, x101);
  fiat_25519_addcarryx_u64(&x107, &x108, x106, x32, x103);
  fiat_25519_addcarryx_u64(&x109, &x110, 0x0, x37, x105);
  fiat_25519_addcarryx_u64(&x111, &x112, x110, x38, x107);
  fiat_25519_addcarryx_u64(&x113, &x114, 0x0, x45, x109);
  fiat_25519_addcarryx_u64(&x115, &x116, x114, x46, x111);
  fiat_25519_addcarryx_u64(&x117, &x118, 0x0, x11, x5);
  fiat_25519_addcarryx_u64(&x119, &x120, x118, x12, x6);
  fiat_25519_addcarryx_u64(&x121, &x122, 0x0, x15, x117);
  fiat_25519_addcarryx_u64(&x123, &x124, x122, x16, x119);
  fiat_25519_addcarryx_u64(&x125, &x126, 0x0, x39, x121);
  fiat_25519_addcarryx_u64(&x127, &x128, x126, x40, x123);
  fiat_25519_addcarryx_u64(&x129, &x130, 0x0, x47, x125);
  fiat_25519_addcarryx_u64(&x131, &x132, x130, x48, x127);
  fiat_25519_addcarryx_u64(&x133, &x134, 0x0, x67, x129);
  x135 = (x134 + x131);
  x136 = ((x133 >> 51) | ((x135 << 13) & UINT64_C(0xffffffffffffffff)));
  x137 = (x133 & UINT64_C(0x7ffffffffffff));
  fiat_25519_addcarryx_u64(&x138, &x139, 0x0, x136, x113);
  x140 = (x139 + x115);
  x141 = ((x138 >> 51) | ((x140 << 13) & UINT64_C(0xffffffffffffffff)));
  x142 = (x138 & UINT64_C(0x7ffffffffffff));
  fiat_25519_addcarryx_u64(&x143, &x144, 0x0, x141, x97);
  x145 = (x144 + x99);
  x146 = ((x143 >> 51) | ((x145 << 13) & UINT64_C(0xffffffffffffffff)));
  x147 = (x143 & UINT64_C(0x7ffffffffffff));
  fiat_25519_addcarryx_u64(&x148, &x149, 0x0, x146, x81);
  x150 = (x149 + x83);
  x151 = ((x148 >> 51) | ((x150 << 13) & UINT64_C(0xffffffffffffffff)));
  x152 = (x148 & UINT64_C(0x7ffffffffffff));
  x153 = (x151 * UINT8_C(0x13));
  x154 = (x68 + x153);
  x155 = (x154 >> 51);
  x156 = (x154 & UINT64_C(0x7ffffffffffff));
  x157 = (x155 + x137);
  x158 = (fiat_25519_uint1)(x157 >> 51);
  x159 = (x157 & UINT64_C(0x7ffffffffffff));
  x160 = (x158 + x142);
  out1[0] = x156;
  out1[1] = x159;
  out1[2] = x160;
  out1[3] = x147;
  out1[4] = x152;
}

/*
 * The function fiat_25519_carry_square squares a field element and reduces the result.
 *
 * Postconditions:
 *   eval out1 mod m = (eval arg1 * eval arg1) mod m
 *
 */
static FIAT_25519_FIAT_INLINE void fiat_25519_carry_square(fiat_25519_tight_field_element out1, const fiat_25519_loose_field_element arg1) {
  uint64_t x1;
  uint64_t x2;
  uint64_t x3;
  uint64_t x4;
  uint64_t x5;
  uint64_t x6;
  uint64_t x7;
  uint64_t x8;
  uint64_t x9;
  uint64_t x10;
  uint64_t x11;
  uint64_t x12;
  uint64_t x13;
  uint64_t x14;
  uint64_t x15;
  uint64_t x16;
  uint64_t x17;
  uint64_t x18;
  uint64_t x19;
  uint64_t x20;
  uint64_t x21;
  uint64_t x22;
  uint64_t x23;
  uint64_t x24;
  uint64_t x25;
  uint64_t x26;
  uint64_t x27;
  uint64_t x28;
  uint64_t x29;
  uint64_t x30;
  uint64_t x31;
  uint64_t x32;
  uint64_t x33;
  uint64_t x34;
  uint64_t x35;
  uint64_t x36;
  uint64_t x37;
  uint64_t x38;
  uint64_t x39;
  fiat_25519_uint1 x40;
  uint64_t x41;
  fiat_25519_uint1 x42;
  uint64_t x43;
  fiat_25519_uint1 x44;
  uint64_t x45;
  fiat_25519_uint1 x46;
  uint64_t x47;
  uint64_t x48;
  uint64_t x49;
  fiat_25519_uint1 x50;
  uint64_t x51;
  fiat_25519_uint1 x52;
  uint64_t x53;
  fiat_25519_uint1 x54;
  uint64_t x55;
  fiat_25519_uint1 x56;
  uint64_t x57;
  fiat_25519_uint1 x58;
  uint64_t x59;
  fiat_25519_uint1 x60;
  uint64_t x61;
  fiat_25519_uint1 x62;
  uint64_t x63;
  fiat_25519_uint1 x64;
  uint64_t x65;
  fiat_25519_uint1 x66;
  uint64_t x67;
  fiat_25519_uint1 x68;
  uint64_t x69;
  fiat_25519_uint1 x70;
  uint64_t x71;
  fiat_25519_uint1 x72;
  uint64_t x73;
  fiat_25519_uint1 x74;
  uint64_t x75;
  fiat_25519_uint1 x76;
  uint64_t x77;
  fiat_25519_uint1 x78;
  uint64_t x79;
  fiat_25519_uint1 x80;
  uint64_t x81;
  fiat_25519_uint1 x82;
  uint64_t x83;
  uint64_t x84;
  uint64_t x85;
  uint64_t x86;
  fiat_25519_uint1 x87;
  uint64_t x88;
  uint64_t x89;
  uint64_t x90;
  uint64_t x91;
  fiat_25519_uint1 x92;
  uint64_t x93;
  uint64_t x94;
  uint64_t x95;
  uint64_t x96;
  fiat_25519_uint1 x97;
  uint64_t x98;
  uint64_t x99;
  uint64_t x100;
  uint64_t x101;
  uint64_t x102;
  uint64_t x103;
  uint64_t x104;
  uint64_t x105;
  fiat_25519_uint1 x106;
  uint64_t x107;
  uint64_t x108;
  x1 = ((arg1[4]) * UINT8_C(0x13));
  x2 = (x1 * 0x2);
  x3 = ((arg1[4]) * 0x2);
  x4 = ((arg1[3]) * UINT8_C(0x13));
  x5 = (x4 * 0x2);
  x6 = ((arg1[3]) * 0x2);
  x7 = ((arg1[2]) * 0x2);
  x8 = ((arg1[1]) * 0x2);
  fiat_25519_mulx_u64(&x9, &x10, (arg1[4]), x1);
  fiat_25519_mulx_u64(&x11, &x12, (arg1[3]), x2);
  fiat_25519_mulx_u64(&x13, &x14, (arg1[3]), x4);
  fiat_25519_mulx_u64(&x15, &x16, (arg1[2]), x2);
  fiat_25519_mulx_u64(&x17, &x18, (arg1[2]), x5);
  fiat_25519_mulx_u64(&x19, &x20, (arg1[2]), (arg1[2]));
  fiat_25519_mulx_u64(&x21, &x22, (arg1[1]), x2);
  fiat_25519_mulx_u64(&x23, &x24, (arg1[1]), x6);
  fiat_25519_mulx_u64(&x25, &x26, (arg1[1]), x7);
  fiat_25519_mulx_u64(&x27, &x28, (arg1[1]), (arg1[1]));
  fiat_25519_mulx_u64(&x29, &x30, (arg1[0]), x3);
  fiat_25519_mulx_u64(&x31, &x32, (arg1[0]), x6);
  fiat_25519_mulx_u64(&x33, &x34, (arg1[0]), x7);
  fiat_25519_mulx_u64(&x35, &x36, (arg1[0]), x8);
  fiat_25519_mulx_u64(&x37, &x38, (arg1[0]), (arg1[0]));
  fiat_25519_addcarryx_u64(&x39, &x40, 0x0, x21, x17);
  fiat_25519_addcarryx_u64(&x41, &x42, x40, x22, x18);
  fiat_25519_addcarryx_u64(&x43, &x44, 0x0, x37, x39);
  fiat_25519_addcarryx_u64(&x45, &x46, x44, x38, x41);
  x47 = ((x43 >> 51) | ((x45 << 13) & UINT64_C(0xffffffffffffffff)));
  x48 = (x43 & UINT64_C(0x7ffffffffffff));
  fiat_25519_addcarryx_u64(&x49, &x50, 0x0, x23, x19);
  fiat_25519_addcarryx_u64(&x51, &x52, x50, x24, x20);
  fiat_25519_addcarryx_u64(&x53, &x54, 0x0, x29, x49);
  fiat_25519_addcarryx_u64(&x55, &x56, x54, x30, x51);
  fiat_25519_addcarryx_u64(&x57, &x58, 0x0, x25, x9);
  fiat_25519_addcarryx_u64(&x59, &x60, x58, x26, x10);
  fiat_25519_addcarryx_u64(&x61, &x62, 0x0, x31, x57);
  fiat_25519_addcarryx_u64(&x63, &x64, x62, x32, x59);
  fiat_25519_addcarryx_u64(&x65, &x66, 0x0, x27, x11);
  fiat_25519_addcarryx_u64(&x67, &x68, x66, x28, x12);
  fiat_25519_addcarryx_u64(&x69, &x70, 0x0, x33, x65);
  fiat_25519_addcarryx_u64(&x71, &x72, x70, x34, x67);
  fiat_25519_addcarryx_u64(&x73, &x74, 0x0, x15, x13);
  fiat_25519_addcarryx_u64(&x75, &x76, x74, x16, x14);
  fiat_25519_addcarryx_u64(&x77, &x78, 0x0, x35, x73);
  fiat_25519_addcarryx_u64(&x79, &x80, x78, x36, x75);
  fiat_25519_addcarryx_u64(&x81, &x82, 0x0, x47, x77);
  x83 = (x82 + x79);
  x84 = ((x81 >> 51) | ((x83 << 13) & UINT64_C(0xffffffffffffffff)));
  x85 = (x81 & UINT64_C(0x7ffffffffffff));
  fiat_25519_addcarryx_u64(&x86, &x87, 0x0, x84, x69);
  x88 = (x87 + x71);
  x89 = ((x86 >> 51) | ((x88 << 13) & UINT64_C(0xffffffffffffffff)));
  x90 = (x86 & UINT64_C(0x7ffffffffffff));
  fiat_25519_addcarryx_u64(&x91, &x92, 0x0, x89, x61);
  x93 = (x92 + x63);
  x94 = ((x91 >> 51) | ((x93 << 13) & UINT64_C(0xffffffffffffffff)));
  x95 = (x91 & UINT64_C(0x7ffffffffffff));
  fiat_25519_addcarryx_u64(&x96, &x97, 0x0, x94, x53);
  x98 = (x97 + x55);
  x99 = ((x96 >> 51) | ((x98 << 13) & UINT64_C(0xffffffffffffffff)));
  x100 = (x96 & UINT64_C(0x7ffffffffffff));
  x101 = (x99 * UINT8_C(0x13));
  x102 = (x48 + x101);
  x103 = (x102 >> 51);
  x104 = (x102 & UINT64_C(0x7ffffffffffff));
  x105 = (x103 + x85);
  x106 = (fiat_25519_uint1)(x105 >> 51);
  x107 = (x105 & UINT64_C(0x7ffffffffffff));
  x108 = (x106 + x90);
  out1[0] = x104;
  out1[1] = x107;
  out1[2] = x108;
  out1[3] = x95;
  out1[4] = x100;
}

/*
 * The function fiat_25519_carry reduces a field element.
 *
 * Postconditions:
 *   eval out1 mod m = eval arg1 mod m
 *
 */
static FIAT_25519_FIAT_INLINE void fiat_25519_carry(fiat_25519_tight_field_element out1, const fiat_25519_loose_field_element arg1) {
  uint64_t x1;
  uint64_t x2;
  uint64_t x3;
  uint64_t x4;
  uint64_t x5;
  uint64_t x6;
  uint64_t x7;
  uint64_t x8;
  uint64_t x9;
  uint64_t x10;
  uint64_t x11;
  uint64_t x12;
  x1 = (arg1[0]);
  x2 = ((x1 >> 51) + (arg1[1]));
  x3 = ((x2 >> 51) + (arg1[2]));
  x4 = ((x3 >> 51) + (arg1[3]));
  x5 = ((x4 >> 51) + (arg1[4]));
  x6 = ((x1 & UINT64_C(0x7ffffffffffff)) + ((x5 >> 51) * UINT8_C(0x13)));
  x7 = ((fiat_25519_uint1)(x6 >> 51) + (x2 & UINT64_C(0x7ffffffffffff)));
  x8 = (x6 & UINT64_C(0x7ffffffffffff));
  x9 = (x7 & UINT64_C(0x7ffffffffffff));
  x10 = ((fiat_25519_uint1)(x7 >> 51) + (x3 & UINT64_C(0x7ffffffffffff)));
  x11 = (x4 & UINT64_C(0x7ffffffffffff));
  x12 = (x5 & UINT64_C(0x7ffffffffffff));
  out1[0] = x8;
  out1[1] = x9;
  out1[2] = x10;
  out1[3] = x11;
  out1[4] = x12;
}

/*
 * The function fiat_25519_add adds two field elements.
 *
 * Postconditions:
 *   eval out1 mod m = (eval arg1 + eval arg2) mod m
 *
 */
static FIAT_25519_FIAT_INLINE void fiat_25519_add(fiat_25519_loose_field_element out1, const fiat_25519_tight_field_element arg1, const fiat_25519_tight_field_element arg2) {
  uint64_t x1;
  uint64_t x2;
  uint64_t x3;
  uint64_t x4;
  uint64_t x5;
  x1 = ((arg1[0]) + (arg2[0]));
  x2 = ((arg1[1]) + (arg2[1]));
  x3 = ((arg1[2]) + (arg2[2]));
  x4 = ((arg1[3]) + (arg2[3]));
  x5 = ((arg1[4]) + (arg2[4]));
  out1[0] = x1;
  out1[1] = x2;
  out1[2] = x3;
  out1[3] = x4;
  out1[4] = x5;
}

/*
 * The function fiat_25519_sub subtracts two field elements.
 *
 * Postconditions:
 *   eval out1 mod m = (eval arg1 - eval arg2) mod m
 *
 */
static FIAT_25519_FIAT_INLINE void fiat_25519_sub(fiat_25519_loose_field_element out1, const fiat_25519_tight_field_element arg1, const fiat_25519_tight_field_element arg2) {
  uint64_t x1;
  uint64_t x2;
  uint64_t x3;
  uint64_t x4;
  uint64_t x5;
  x1 = ((UINT64_C(0xfffffffffffda) + (arg1[0])) - (arg2[0]));
  x2 = ((UINT64_C(0xffffffffffffe) + (arg1[1])) - (arg2[1]));
  x3 = ((UINT64_C(0xffffffffffffe) + (arg1[2])) - (arg2[2]));
  x4 = ((UINT64_C(0xffffffffffffe) + (arg1[3])) - (arg2[3]));
  x5 = ((UINT64_C(0xffffffffffffe) + (arg1[4])) - (arg2[4]));
  out1[0] = x1;
  out1[1] = x2;
  out1[2] = x3;
  out1[3] = x4;
  out1[4] = x5;
}

/*
 * The function fiat_25519_opp negates a field element.
 *
 * Postconditions:
 *   eval out1 mod m = -eval arg1 mod m
 *
 */
static FIAT_25519_FIAT_INLINE void fiat_25519_opp(fiat_25519_loose_field_element out1, const fiat_25519_tight_field_element arg1) {
  uint64_t x1;
  uint64_t x2;
  uint64_t x3;
  uint64_t x4;
  uint64_t x5;
  x1 = (UINT64_C(0xfffffffffffda) - (arg1[0]));
  x2 = (UINT64_C(0xffffffffffffe) - (arg1[1]));
  x3 = (UINT64_C(0xffffffffffffe) - (arg1[2]));
  x4 = (UINT64_C(0xffffffffffffe) - (arg1[3]));
  x5 = (UINT64_C(0xffffffffffffe) - (arg1[4]));
  out1[0] = x1;
  out1[1] = x2;
  out1[2] = x3;
  out1[3] = x4;
  out1[4] = x5;
}

/*
 * The function fiat_25519_selectznz is a multi-limb conditional select.
 *
 * Postconditions:
 *   out1 = (if arg1 = 0 then arg2 else arg3)
 *
 * Input Bounds:
 *   arg1: [0x0 ~> 0x1]
 *   arg2: [[0x0 ~> 0xffffffffffffffff], [0x0 ~> 0xffffffffffffffff], [0x0 ~> 0xffffffffffffffff], [0x0 ~> 0xffffffffffffffff], [0x0 ~> 0xffffffffffffffff]]
 *   arg3: [[0x0 ~> 0xffffffffffffffff], [0x0 ~> 0xffffffffffffffff], [0x0 ~> 0xffffffffffffffff], [0x0 ~> 0xffffffffffffffff], [0x0 ~> 0xffffffffffffffff]]
 * Output Bounds:
 *   out1: [[0x0 ~> 0xffffffffffffffff], [0x0 ~> 0xffffffffffffffff], [0x0 ~> 0xffffffffffffffff], [0x0 ~> 0xffffffffffffffff], [0x0 ~> 0xffffffffffffffff]]
 */
static FIAT_25519_FIAT_INLINE void fiat_25519_selectznz(uint64_t out1[5], fiat_25519_uint1 arg1, const uint64_t arg2[5], const uint64_t arg3[5]) {
  uint64_t x1;
  uint64_t x2;
  uint64_t x3;
  uint64_t x4;
  uint64_t x5;
  fiat_25519_cmovznz_u64(&x1, arg1, (arg2[0]), (arg3[0]));
  fiat_25519_cmovznz_u64(&x2, arg1, (arg2[1]), (arg3[1]));
  fiat_25519_cmovznz_u64(&x3, arg1, (arg2[2]), (arg3[2]));
  fiat_25519_cmovznz_u64(&x4, arg1, (arg2[3]), (arg3[3]));
  fiat_25519_cmovznz_u64(&x5, arg1, (arg2[4]), (arg3[4]));
  out1[0] = x1;
  out1[1] = x2;
  out1[2] = x3;
  out1[3] = x4;
  out1[4] = x5;
}

/*
 * The function fiat_25519_to_bytes serializes a field element to bytes in little-endian order.
 *
 * Postconditions:
 *   out1 = map (λ x, ⌊((eval arg1 mod m) mod 2^(8 * (x + 1))) / 2^(8 * x)⌋) [0..31]
 *
 * Output Bounds:
 *   out1: [[0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0x7f]]
 */
static FIAT_25519_FIAT_INLINE void fiat_25519_to_bytes(uint8_t out1[32], const fiat_25519_tight_field_element arg1) {
  uint64_t x1;
  fiat_25519_uint1 x2;
  uint64_t x3;
  fiat_25519_uint1 x4;
  uint64_t x5;
  fiat_25519_uint1 x6;
  uint64_t x7;
  fiat_25519_uint1 x8;
  uint64_t x9;
  fiat_25519_uint1 x10;
  uint64_t x11;
  uint64_t x12;
  fiat_25519_uint1 x13;
  uint64_t x14;
  fiat_25519_uint1 x15;
  uint64_t x16;
  fiat_25519_uint1 x17;
  uint64_t x18;
  fiat_25519_uint1 x19;
  uint64_t x20;
  fiat_25519_uint1 x21;
  uint64_t x22;
  uint64_t x23;
  uint64_t x24;
  uint64_t x25;
  uint8_t x26;
  uint64_t x27;
  uint8_t x28;
  uint64_t x29;
  uint8_t x30;
  uint64_t x31;
  uint8_t x32;
  uint64_t x33;
  uint8_t x34;
  uint64_t x35;
  uint8_t x36;
  uint8_t x37;
  uint64_t x38;
  uint8_t x39;
  uint64_t x40;
  uint8_t x41;
  uint64_t x42;
  uint8_t x43;
  uint64_t x44;
  uint8_t x45;
  uint64_t x46;
  uint8_t x47;
  uint64_t x48;
  uint8_t x49;
  uint8_t x50;
  uint64_t x51;
  uint8_t x52;
  uint64_t x53;
  uint8_t x54;
  uint64_t x55;
  uint8_t x56;
  uint64_t x57;
  uint8_t x58;
  uint64_t x59;
  uint8_t x60;
  uint64_t x61;
  uint8_t x62;
  uint64_t x63;
  uint8_t x64;
  fiat_25519_uint1 x65;
  uint64_t x66;
  uint8_t x67;
  uint64_t x68;
  uint8_t x69;
  uint64_t x70;
  uint8_t x71;
  uint64_t x72;
  uint8_t x73;
  uint64_t x74;
  uint8_t x75;
  uint64_t x76;
  uint8_t x77;
  uint8_t x78;
  uint64_t x79;
  uint8_t x80;
  uint64_t x81;
  uint8_t x82;
  uint64_t x83;
  uint8_t x84;
  uint64_t x85;
  uint8_t x86;
  uint64_t x87;
  uint8_t x88;
  uint64_t x89;
  uint8_t x90;
  uint8_t x91;
  fiat_25519_subborrowx_u51(&x1, &x2, 0x0, (arg1[0]), UINT64_C(0x7ffffffffffed));
  fiat_25519_subborrowx_u51(&x3, &x4, x2, (arg1[1]), UINT64_C(0x7ffffffffffff));
  fiat_25519_subborrowx_u51(&x5, &x6, x4, (arg1[2]), UINT64_C(0x7ffffffffffff));
  fiat_25519_subborrowx_u51(&x7, &x8, x6, (arg1[3]), UINT64_C(0x7ffffffffffff));
  fiat_25519_subborrowx_u51(&x9, &x10, x8, (arg1[4]), UINT64_C(0x7ffffffffffff));
  fiat_25519_cmovznz_u64(&x11, x10, 0x0, UINT64_C(0xffffffffffffffff));
  fiat_25519_addcarryx_u51(&x12, &x13, 0x0, x1, (x11 & UINT64_C(0x7ffffffffffed)));
  fiat_25519_addcarryx_u51(&x14, &x15, x13, x3, (x11 & UINT64_C(0x7ffffffffffff)));
  fiat_25519_addcarryx_u51(&x16, &x17, x15, x5, (x11 & UINT64_C(0x7ffffffffffff)));
  fiat_25519_addcarryx_u51(&x18, &x19, x17, x7, (x11 & UINT64_C(0x7ffffffffffff)));
  fiat_25519_addcarryx_u51(&x20, &x21, x19, x9, (x11 & UINT64_C(0x7ffffffffffff)));
  x22 = (x20 << 4);
  x23 = (x18 * (uint64_t)0x2);
  x24 = (x16 << 6);
  x25 = (x14 << 3);
  x26 = (uint8_t)(x12 & UINT8_C(0xff));
  x27 = (x12 >> 8);
  x28 = (uint8_t)(x27 & UINT8_C(0xff));
  x29 = (x27 >> 8);
  x30 = (uint8_t)(x29 & UINT8_C(0xff));
  x31 = (x29 >> 8);
  x32 = (uint8_t)(x31 & UINT8_C(0xff));
  x33 = (x31 >> 8);
  x34 = (uint8_t)(x33 & UINT8_C(0xff));
  x35 = (x33 >> 8);
  x36 = (uint8_t)(x35 & UINT8_C(0xff));
  x37 = (uint8_t)(x35 >> 8);
  x38 = (x25 + (uint64_t)x37);
  x39 = (uint8_t)(x38 & UINT8_C(0xff));
  x40 = (x38 >> 8);
  x41 = (uint8_t)(x40 & UINT8_C(0xff));
  x42 = (x40 >> 8);
  x43 = (uint8_t)(x42 & UINT8_C(0xff));
  x44 = (x42 >> 8);
  x45 = (uint8_t)(x44 & UINT8_C(0xff));
  x46 = (x44 >> 8);
  x47 = (uint8_t)(x46 & UINT8_C(0xff));
  x48 = (x46 >> 8);
  x49 = (uint8_t)(x48 & UINT8_C(0xff));
  x50 = (uint8_t)(x48 >> 8);
  x51 = (x24 + (uint64_t)x50);
  x52 = (uint8_t)(x51 & UINT8_C(0xff));
  x53 = (x51 >> 8);
  x54 = (uint8_t)(x53 & UINT8_C(0xff));
  x55 = (x53 >> 8);
  x56 = (uint8_t)(x55 & UINT8_C(0xff));
  x57 = (x55 >> 8);
  x58 = (uint8_t)(x57 & UINT8_C(0xff));
  x59 = (x57 >> 8);
  x60 = (uint8_t)(x59 & UINT8_C(0xff));
  x61 = (x59 >> 8);
  x62 = (uint8_t)(x61 & UINT8_C(0xff));
  x63 = (x61 >> 8);
  x64 = (uint8_t)(x63 & UINT8_C(0xff));
  x65 = (fiat_25519_uint1)(x63 >> 8);
  x66 = (x23 + (uint64_t)x65);
  x67 = (uint8_t)(x66 & UINT8_C(0xff));
  x68 = (x66 >> 8);
  x69 = (uint8_t)(x68 & UINT8_C(0xff));
  x70 = (x68 >> 8);
  x71 = (uint8_t)(x70 & UINT8_C(0xff));
  x72 = (x70 >> 8);
  x73 = (uint8_t)(x72 & UINT8_C(0xff));
  x74 = (x72 >> 8);
  x75 = (uint8_t)(x74 & UINT8_C(0xff));
  x76 = (x74 >> 8);
  x77 = (uint8_t)(x76 & UINT8_C(0xff));
  x78 = (uint8_t)(x76 >> 8);
  x79 = (x22 + (uint64_t)x78);
  x80 = (uint8_t)(x79 & UINT8_C(0xff));
  x81 = (x79 >> 8);
  x82 = (uint8_t)(x81 & UINT8_C(0xff));
  x83 = (x81 >> 8);
  x84 = (uint8_t)(x83 & UINT8_C(0xff));
  x85 = (x83 >> 8);
  x86 = (uint8_t)(x85 & UINT8_C(0xff));
  x87 = (x85 >> 8);
  x88 = (uint8_t)(x87 & UINT8_C(0xff));
  x89 = (x87 >> 8);
  x90 = (uint8_t)(x89 & UINT8_C(0xff));
  x91 = (uint8_t)(x89 >> 8);
  out1[0] = x26;
  out1[1] = x28;
  out1[2] = x30;
  out1[3] = x32;
  out1[4] = x34;
  out1[5] = x36;
  out1[6] = x39;
  out1[7] = x41;
  out1[8] = x43;
  out1[9] = x45;
  out1[10] = x47;
  out1[11] = x49;
  out1[12] = x52;
  out1[13] = x54;
  out1[14] = x56;
  out1[15] = x58;
  out1[16] = x60;
  out1[17] = x62;
  out1[18] = x64;
  out1[19] = x67;
  out1[20] = x69;
  out1[21] = x71;
  out1[22] = x73;
  out1[23] = x75;
  out1[24] = x77;
  out1[25] = x80;
  out1[26] = x82;
  out1[27] = x84;
  out1[28] = x86;
  out1[29] = x88;
  out1[30] = x90;
  out1[31] = x91;
}

/*
 * The function fiat_25519_from_bytes deserializes a field element from bytes in little-endian order.
 *
 * Postconditions:
 *   eval out1 mod m = bytes_eval arg1 mod m
 *
 * Input Bounds:
 *   arg1: [[0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0x7f]]
 */
static FIAT_25519_FIAT_INLINE void fiat_25519_from_bytes(fiat_25519_tight_field_element out1, const uint8_t arg1[32]) {
  uint64_t x1;
  uint64_t x2;
  uint64_t x3;
  uint64_t x4;
  uint64_t x5;
  uint64_t x6;
  uint64_t x7;
  uint64_t x8;
  uint64_t x9;
  uint64_t x10;
  uint64_t x11;
  uint64_t x12;
  uint64_t x13;
  uint64_t x14;
  uint64_t x15;
  uint64_t x16;
  uint64_t x17;
  uint64_t x18;
  uint64_t x19;
  uint64_t x20;
  uint64_t x21;
  uint64_t x22;
  uint64_t x23;
  uint64_t x24;
  uint64_t x25;
  uint64_t x26;
  uint64_t x27;
  uint64_t x28;
  uint64_t x29;
  uint64_t x30;
  uint64_t x31;
  uint8_t x32;
  uint64_t x33;
  uint64_t x34;
  uint64_t x35;
  uint64_t x36;
  uint64_t x37;
  uint64_t x38;
  uint64_t x39;
  uint8_t x40;
  uint64_t x41;
  uint64_t x42;
  uint64_t x43;
  uint64_t x44;
  uint64_t x45;
  uint64_t x46;
  uint64_t x47;
  uint8_t x48;
  uint64_t x49;
  uint64_t x50;
  uint64_t x51;
  uint64_t x52;
  uint64_t x53;
  uint64_t x54;
  uint64_t x55;
  uint64_t x56;
  uint8_t x57;
  uint64_t x58;
  uint64_t x59;
  uint64_t x60;
  uint64_t x61;
  uint64_t x62;
  uint64_t x63;
  uint64_t x64;
  uint8_t x65;
  uint64_t x66;
  uint64_t x67;
  uint64_t x68;
  uint64_t x69;
  uint64_t x70;
  uint64_t x71;
  x1 = ((uint64_t)(arg1[31]) << 44);
  x2 = ((uint64_t)(arg1[30]) << 36);
  x3 = ((uint64_t)(arg1[29]) << 28);
  x4 = ((uint64_t)(arg1[28]) << 20);
  x5 = ((uint64_t)(arg1[27]) << 12);
  x6 = ((uint64_t)(arg1[26]) << 4);
  x7 = ((uint64_t)(arg1[25]) << 47);
  x8 = ((uint64_t)(arg1[24]) << 39);
  x9 = ((uint64_t)(arg1[23]) << 31);
  x10 = ((uint64_t)(arg1[22]) << 23);
  x11 = ((uint64_t)(arg1[21]) << 15);
  x12 = ((uint64_t)(arg1[20]) << 7);
  x13 = ((uint64_t)(arg1[19]) << 50);
  x14 = ((uint64_t)(arg1[18]) << 42);
  x15 = ((uint64_t)(arg1[17]) << 34);
  x16 = ((uint64_t)(arg1[16]) << 26);
  x17 = ((uint64_t)(arg1[15]) << 18);
  x18 = ((uint64_t)(arg1[14]) << 10);
  x19 = ((uint64_t)(arg1[13]) << 2);
  x20 = ((uint64_t)(arg1[12]) << 45);
  x21 = ((uint64_t)(arg1[11]) << 37);
  x22 = ((uint64_t)(arg1[10]) << 29);
  x23 = ((uint64_t)(arg1[9]) << 21);
  x24 = ((uint64_t)(arg1[8]) << 13);
  x25 = ((uint64_t)(arg1[7]) << 5);
  x26 = ((uint64_t)(arg1[6]) << 48);
  x27 = ((uint64_t)(arg1[5]) << 40);
  x28 = ((uint64_t)(arg1[4]) << 32);
  x29 = ((uint64_t)(arg1[3]) << 24);
  x30 = ((uint64_t)(arg1[2]) << 16);
  x31 = ((uint64_t)(arg1[1]) << 8);
  x32 = (arg1[0]);
  x33 = (x31 + (uint64_t)x32);
  x34 = (x30 + x33);
  x35 = (x29 + x34);
  x36 = (x28 + x35);
  x37 = (x27 + x36);
  x38 = (x26 + x37);
  x39 = (x38 & UINT64_C(0x7ffffffffffff));
  x40 = (uint8_t)(x38 >> 51);
  x41 = (x25 + (uint64_t)x40);
  x42 = (x24 + x41);
  x43 = (x23 + x42);
  x44 = (x22 + x43);
  x45 = (x21 + x44);
  x46 = (x20 + x45);
  x47 = (x46 & UINT64_C(0x7ffffffffffff));
  x48 = (uint8_t)(x46 >> 51);
  x49 = (x19 + (uint64_t)x48);
  x50 = (x18 + x49);
  x51 = (x17 + x50);
  x52 = (x16 + x51);
  x53 = (x15 + x52);
  x54 = (x14 + x53);
  x55 = (x13 + x54);
  x56 = (x55 & UINT64_C(0x7ffffffffffff));
  x57 = (uint8_t)(x55 >> 51);
  x58 = (x12 + (uint64_t)x57);
  x59 = (x11 + x58);
  x60 = (x10 + x59);
  x61 = (x9 + x60);
  x62 = (x8 + x61);
  x63 = (x7 + x62);
  x64 = (x63 & UINT64_C(0x7ffffffffffff));
  x65 = (uint8_t)(x63 >> 51);
  x66 = (x6 + (uint64_t)x65);
  x67 = (x5 + x66);
  x68 = (x4 + x67);
  x69 = (x3 + x68);
  x70 = (x2 + x69);
  x71 = (x1 + x70);
  out1[0] = x39;
  out1[1] = x47;
  out1[2] = x56;
  out1[3] = x64;
  out1[4] = x71;
}

/*
 * The function fiat_25519_relax is the identity function converting from tight field elements to loose field elements.
 *
 * Postconditions:
 *   out1 = arg1
 *
 */
static FIAT_25519_FIAT_INLINE void fiat_25519_relax(fiat_25519_loose_field_element out1, const fiat_25519_tight_field_element arg1) {
  uint64_t x1;
  uint64_t x2;
  uint64_t x3;
  uint64_t x4;
  uint64_t x5;
  x1 = (arg1[0]);
  x2 = (arg1[1]);
  x3 = (arg1[2]);
  x4 = (arg1[3]);
  x5 = (arg1[4]);
  out1[0] = x1;
  out1[1] = x2;
  out1[2] = x3;
  out1[3] = x4;
  out1[4] = x5;
}

/*
 * The function fiat_25519_carry_scmul_121666 multiplies a field element by 121666 and reduces the result.
 *
 * Postconditions:
 *   eval out1 mod m = (121666 * eval arg1) mod m
 *
 */
static FIAT_25519_FIAT_INLINE void fiat_25519_carry_scmul_121666(fiat_25519_tight_field_element out1, const fiat_25519_loose_field_element arg1) {
  uint64_t x1;
  uint64_t x2;
  uint64_t x3;
  uint64_t x4;
  uint64_t x5;
  uint64_t x6;
  uint64_t x7;
  uint64_t x8;
  uint64_t x9;
  uint64_t x10;
  uint64_t x11;
  uint64_t x12;
  uint64_t x13;
  fiat_25519_uint1 x14;
  uint64_t x15;
  uint64_t x16;
  uint64_t x17;
  uint64_t x18;
  fiat_25519_uint1 x19;
  uint64_t x20;
  uint64_t x21;
  uint64_t x22;
  uint64_t x23;
  fiat_25519_uint1 x24;
  uint64_t x25;
  uint64_t x26;
  uint64_t x27;
  uint64_t x28;
  fiat_25519_uint1 x29;
  uint64_t x30;
  uint64_t x31;
  uint64_t x32;
  uint64_t x33;
  uint64_t x34;
  fiat_25519_uint1 x35;
  uint64_t x36;
  uint64_t x37;
  fiat_25519_uint1 x38;
  uint64_t x39;
  uint64_t x40;
  fiat_25519_mulx_u64(&x1, &x2, UINT32_C(0x1db42), (arg1[4]));
  fiat_25519_mulx_u64(&x3, &x4, UINT32_C(0x1db42), (arg1[3]));
  fiat_25519_mulx_u64(&x5, &x6, UINT32_C(0x1db42), (arg1[2]));
  fiat_25519_mulx_u64(&x7, &x8, UINT32_C(0x1db42), (arg1[1]));
  fiat_25519_mulx_u64(&x9, &x10, UINT32_C(0x1db42), (arg1[0]));
  x11 = ((x9 >> 51) | ((x10 << 13) & UINT64_C(0xffffffffffffffff)));
  x12 = (x9 & UINT64_C(0x7ffffffffffff));
  fiat_25519_addcarryx_u64(&x13, &x14, 0x0, x11, x7);
  x15 = (x14 + x8);
  x16 = ((x13 >> 51) | ((x15 << 13) & UINT64_C(0xffffffffffffffff)));
  x17 = (x13 & UINT64_C(0x7ffffffffffff));
  fiat_25519_addcarryx_u64(&x18, &x19, 0x0, x16, x5);
  x20 = (x19 + x6);
  x21 = ((x18 >> 51) | ((x20 << 13) & UINT64_C(0xffffffffffffffff)));
  x22 = (x18 & UINT64_C(0x7ffffffffffff));
  fiat_25519_addcarryx_u64(&x23, &x24, 0x0, x21, x3);
  x25 = (x24 + x4);
  x26 = ((x23 >> 51) | ((x25 << 13) & UINT64_C(0xffffffffffffffff)));
  x27 = (x23 & UINT64_C(0x7ffffffffffff));
  fiat_25519_addcarryx_u64(&x28, &x29, 0x0, x26, x1);
  x30 = (x29 + x2);
  x31 = ((x28 >> 51) | ((x30 << 13) & UINT64_C(0xffffffffffffffff)));
  x32 = (x28 & UINT64_C(0x7ffffffffffff));
  x33 = (x31 * UINT8_C(0x13));
  x34 = (x12 + x33);
  x35 = (fiat_25519_uint1)(x34 >> 51);
  x36 = (x34 & UINT64_C(0x7ffffffffffff));
  x37 = (x35 + x17);
  x38 = (fiat_25519_uint1)(x37 >> 51);
  x39 = (x37 & UINT64_C(0x7ffffffffffff));
  x40 = (x38 + x22);
  out1[0] = x36;
  out1[1] = x39;
  out1[2] = x40;
  out1[3] = x27;
  out1[4] = x32;
}