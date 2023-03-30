#include "s21_string.h"

#include <check.h>
#include <errno.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *str1[200];
char *str2[200];
char *str3[200];

int result(int num) {
  int res = 0;
  if (num > 0)
    res = 1;
  else if (num < 0)
    res = -1;
  return res;
}

START_TEST(memchrTest) {
  char str_mem1[250] = "dreamteam";
  char str_mem2[250] = "dreamteam444";
  char str_mem3[250] = "fuck";
  ck_assert_ptr_eq(s21_memchr(str_mem1, 'f', 9), memchr(str_mem1, 'f', 9));
  ck_assert_ptr_eq(s21_memchr(str_mem2, 'e', 2), memchr(str_mem2, 'e', 2));
  ck_assert_ptr_eq(s21_memchr(str_mem3, '0', 9), memchr(str_mem3, '0', 9));
}
END_TEST

START_TEST(memcmpTest) {
  const char mass_memcmp[250] = "wake me up";
  const char mass_memcmp1[250] = "wake3";
  const char mass_memcmp2[250] = "wakemeup";
  int s21_res = s21_memcmp("wake meup", mass_memcmp, 10);
  int res = memcmp("wake meup", mass_memcmp, 10);
  ck_assert_int_eq(result(s21_res), result(res));
  ck_assert_int_eq(result(s21_memcmp(mass_memcmp1, "wake", 0)),
                   memcmp(mass_memcmp1, "wake", 0));
  ck_assert_int_eq(result(s21_memcmp("wake3", mass_memcmp2, 8)),
                   result(memcmp("wake3", mass_memcmp2, 8)));
}
END_TEST

START_TEST(memcpyTest) {
  char mas_mem1[250] = "wellthisshitdoesnwork";
  ck_assert_str_eq(s21_memcpy(mas_mem1, "fuckthis", 4),
                   memcpy(mas_mem1, "fuckthis", 4));
  ck_assert_str_eq(s21_memcpy(mas_mem1, "something", 9),
                   memcpy(mas_mem1, "something", 9));
  ck_assert_str_eq(s21_memcpy(mas_mem1, "hell\0no", 6),
                   memcpy(mas_mem1, "hell\0no", 6));
}
END_TEST

START_TEST(memmoveTest) {
  *str1 = "well";
  *str2 = "done";
  ck_assert_str_eq(s21_memmove(str1, str2, 10), memmove(str1, str2, 10));
  *str1 = "123";
  *str2 = "99999";
  ck_assert_str_eq(s21_memmove(str1, str2, 120), memmove(str1, str2, 120));
  *str1 = "";
  *str2 = "123";
  ck_assert_str_eq(s21_memmove(str1, str2, 12), memmove(str1, str2, 12));
  char memmove1[40] = "sqwozbab squidward";
  ck_assert_str_eq(s21_memmove(memmove1 + 5, memmove1, 6),
                   memmove(memmove1 + 5, memmove1, 6));
}
END_TEST

START_TEST(memsetTest) {
  *str1 = "well";
  *str2 = "99999";
  ck_assert_str_eq(s21_memset(str1, 1, 10), memset(str1, 1, 10));
  *str1 = "well";
  *str2 = "99999";
  ck_assert_str_eq(s21_memset(str2, 23, 2), memset(str2, 23, 2));
  *str1 = "well";
  ck_assert_str_eq(s21_memset(str1, 23, 2), memset(str1, 4, 2));
}
END_TEST

START_TEST(strcatTest) {
  char str6[250] = "marinara";
  char str7[250] = "tasty";
  char str8[250] = "";
  ck_assert_str_eq(s21_strcat(str6, "tasty"), strcat(str6, "tasty"));
  ck_assert_str_eq(s21_strcat(str7, "123"), strcat(str7, "123"));
  ck_assert_str_eq(s21_strcat(str8, "\0"), strcat(str8, "\0"));
}
END_TEST

START_TEST(strncatTest) {
  char str9[250] = "marinara";
  char str10[250] = "tasty";
  char str11[250] = "";
  ck_assert_str_eq(s21_strncat(str9, str10, 5), strncat(str9, str10, 5));
  ck_assert_str_eq(s21_strncat(str10, str9, 3), strncat(str10, str9, 3));
  ck_assert_str_eq(s21_strncat(str11, "\0", 0), strncat(str11, "\0", 0));
}
END_TEST

START_TEST(strchrTest) {
  char *strchr1 = "01234567896";
  int strrchr2 = 6;
  ck_assert_ptr_eq(s21_strchr("0123456", 'z'), strchr("0123456", 'z'));
  ck_assert_ptr_eq(s21_strrchr(strchr1, strrchr2), strrchr(strchr1, strrchr2));
}
END_TEST

START_TEST(strcmpTest) {
  const char mass_strcmp[210] = "1";
  ck_assert_int_eq(s21_strcmp("1", mass_strcmp), strcmp("1", mass_strcmp));
  ck_assert_int_eq(s21_strcmp("barin", "barin"), 0);
  ck_assert_int_eq(s21_strcmp("milyi\0paren", "milyi\0paren"), 0);
}
END_TEST

START_TEST(strncmpTest) {
  const char mass_strnc[210] = "matrix";
  int strn_test = strncmp("matrix", mass_strnc, 6);
  ck_assert_int_eq(s21_strncmp("sqwozbab", "sqwozbab", 5), 0);
  ck_assert_int_eq(s21_strncmp("motherfaka", "motherfucker", 5), 0);
  ck_assert_int_eq(s21_strncmp("sqwoz\0bab", "sqwoz\0bab", 6), 0);
  ck_assert_int_eq(s21_strncmp("sqwozbab", "squidward", 5), 2);
  ck_assert_int_eq(s21_strncmp("matrix", "matrix", 6), strn_test);
}
END_TEST

START_TEST(strcpyTest) {
  char str13[220] = "help";
  char str14[220] = "";
  char str15[220] = "/0";
  ck_assert_str_eq(s21_strcpy(str13, "abc"), strcpy(str13, "abc"));
  ck_assert_str_eq(s21_strcpy(str14, "123"), strcpy(str14, "123"));
  ck_assert_str_eq(s21_strcpy(str15, "winter"), strcpy(str15, "wint"));
}
END_TEST

START_TEST(strncpyTest) {
  char str16[220] = "help";
  char str17[220] = "";
  char str55[220] = "";
  char str18[220] = "hurricane";
  ck_assert_str_eq(s21_strncpy(str16, "abc", 4), strncpy(str16, "abc", 4));
  ck_assert_str_eq(s21_strncpy(str17, "123", 4), strncpy(str55, "123", 4));
  ck_assert_str_eq(s21_strncpy(str18, "winter", 7),
                   strncpy(str18, "winter", 7));
}
END_TEST

START_TEST(strcspnTest) {
  char *strcspn2 = "0123456789";
  ck_assert_int_eq(s21_strcspn(strcspn2, "9876"), strcspn(strcspn2, "9876"));
  ck_assert_int_eq(s21_strcspn("\0", " "), strcspn("\0", " "));
}
END_TEST

START_TEST(strerrorTest) {
  ck_assert_str_eq(s21_strerror(0), strerror(0));
  ck_assert_str_eq(s21_strerror(14), strerror(14));
  ck_assert_str_eq(s21_strerror(34), strerror(34));
  ck_assert_str_eq(s21_strerror(-10), strerror(-10));
  ck_assert_str_eq(s21_strerror(154), strerror(154));
}
END_TEST

START_TEST(strlenTest) {
  ck_assert_int_eq(s21_strlen("wor\0k"), strlen("wor\0k"));
  ck_assert_int_eq(s21_strlen("like the police"), strlen("like the police"));
}
END_TEST

START_TEST(strpbrkTest) {
  char *suck = "123456";
  char *pbrk = "614";
  ck_assert_str_eq(s21_strpbrk(suck, pbrk), strpbrk(suck, pbrk));
}
END_TEST

START_TEST(strrchrTest) {
  char *strrchr1 = "why does my heart";
  char *strrchr2 = "feel s\no bad";
  ck_assert_ptr_eq(s21_strrchr(strrchr1, 'd'), strrchr(strrchr1, 'd'));
  ck_assert_ptr_eq(s21_strrchr(strrchr1, 'z'), strrchr(strrchr1, 'z'));
  ck_assert_ptr_eq(s21_strrchr(strrchr2, 'b'), strrchr(strrchr2, 'b'));
}
END_TEST

START_TEST(strspnTest) {
  ck_assert_int_eq(s21_strspn("this is a test", "isht"),
                   strspn("this is a test", "isht"));
  ck_assert_int_eq(s21_strspn("0123456789", "210"),
                   strspn("0123456789", "210"));
  ck_assert_int_eq(s21_strspn("\0", " "), strspn("\0", " "));
}
END_TEST

START_TEST(strstrTest) {
  ck_assert_ptr_eq(s21_strstr("thisisatest", "test"),
                   strstr("thisisatest", "test"));
  ck_assert_ptr_eq(s21_strstr("1234567", "123"), strstr("1234567", "123"));
  ck_assert_ptr_eq(s21_strstr("I was gonna come to you", ""),
                   strstr("I was gonna come to you", ""));
}
END_TEST

START_TEST(strtokTest) {
  char str19[250] = "test1/test2/test3/test4";
  char str20[250] = "Have good day";
  char str21[250] = "123.456.555.545";
  char str22[250] = "the-dreamteam-vs-world";
  ck_assert_str_eq(s21_strtok(str19, "/"), strtok(str19, "/"));
  ck_assert_str_eq(s21_strtok(str20, " "), strtok(str20, " "));
  ck_assert_str_eq(s21_strtok(str21, "."), strtok(str21, "."));
  ck_assert_str_eq(s21_strtok(str22, "-"), strtok(str22, "-"));
  char strtok31[100] = "NOTHING";
  char delitel2[10] = "";
  ck_assert_str_eq(s21_strtok(strtok31, delitel2), strtok(strtok31, delitel2));
  char strtok3[250] = "Something something, fuck, i've got something for this";
  char strtok4[250] = "Something something, fuck, i've got something for this";
  char delitel[250] = ",";
  ck_assert_str_eq(s21_strtok(strtok3, delitel), strtok(strtok4, delitel));
  ck_assert_str_eq(s21_strtok(s21_NULL, delitel), strtok(s21_NULL, delitel));
  ck_assert_str_eq(s21_strtok(s21_NULL, delitel), strtok(s21_NULL, delitel));
}
END_TEST

START_TEST(toUpperTest) {
  char str23[230] = "baby, if i give it";
  const char str231[230] = "BABY, IF I GIVE IT";
  char *res = s21_to_upper(str23);
  if (s21_NULL != res) {
    ck_assert_str_eq(res, str231);
  }
  free(res);
  res = s21_NULL;
}
END_TEST

START_TEST(toUpperTest1) {
  char str24[220] = "023fuckedi4";
  const char str241[220] = "023FUCKEDI4";
  char *res1 = s21_to_upper(str24);
  if (s21_NULL != res1) {
    ck_assert_str_eq(res1, str241);
  }
  free(res1);
  res1 = s21_NULL;
}
END_TEST

START_TEST(toLowerTest) {
  const char rst_low[230] = "baby, if i give it";
  const char experiment1[230] = "BABY, IF I GIVE IT";
  char *res2 = s21_to_lower(experiment1);
  ck_assert_str_eq(res2, rst_low);
  free(res2);
  // res2 = s21_NULL;
}
END_TEST

START_TEST(toLowerTest1) {
  const char str24[220] = "02394";
  const char str241[220] = "02394";
  char *res3 = s21_to_lower(str241);
  if (s21_NULL != res3) {
    ck_assert_str_eq(res3, str24);
  }
  free(res3);
  res3 = s21_NULL;
}
END_TEST

START_TEST(insertTest) {
  char mass_insert1[50] = "Get Schwifty!";
  char mass_insert2[50] = "-WUBBA LUBBA DUB-DUB!";
  const char insert_result[50] = "Get Schwifty!-WUBBA LUBBA DUB-DUB!";
  char *insert21 = (char *)s21_insert(mass_insert1, mass_insert2, 13);
  if (insert21 != s21_NULL) {
    ck_assert_str_eq(insert21, insert_result);
  }
  free(insert21);
  insert21 = s21_NULL;
}
END_TEST

START_TEST(insertTest1) {
  char mass_insert3[220] = "";
  char mass_insert4[220] = "Get Schwifty!";
  const char insert_result1[220] = "Get Schwifty!";
  char *insert212 = (char *)s21_insert(mass_insert3, mass_insert4, 0);
  if (insert212 != s21_NULL) {
    ck_assert_str_eq(insert212, insert_result1);
  }
  free(insert212);
  insert212 = s21_NULL;
}
END_TEST

START_TEST(insertTest2) {
  char mass_insert3[220] = "anaconda";
  char mass_insert4[220] = "Get Schwifty!";
  char *insert212 = (char *)s21_insert(mass_insert3, mass_insert4, 10500);
  ck_assert_ptr_eq(insert212, s21_NULL);
  free(insert212);
  insert212 = s21_NULL;
}
END_TEST

START_TEST(trimTest) {
  char trim_mass1[220] = "***Who Rock***";
  char trim_mass2[210] = "*";
  const char res_trim[220] = "Who Rock";
  char *trim_res = s21_trim(trim_mass1, trim_mass2);
  if (trim_res != s21_NULL) {
    ck_assert_str_eq(trim_res, res_trim);
  }
  free(trim_res);
  trim_res = s21_NULL;
}
END_TEST

START_TEST(trimTest1) {
  char trim3[220] = " mambo-jambo ";
  char trim4[220] = " ";
  const char trim_res2[220] = "mambo-jambo";
  char *trim_fun2 = s21_trim(trim3, trim4);
  if (trim_fun2 != s21_NULL) {
    ck_assert_str_eq(trim_fun2, trim_res2);
  }
  free(trim_fun2);
  trim_fun2 = s21_NULL;
}
END_TEST

START_TEST(sprintf_int) {
  char str31[100] = "HE";
  char str32[100] = "HU";

  const char format[] = "%10d %+5d %d %+.26d %- 9d %-+10.5d %+ld %-9hd";
  int a = 50, a1 = -5, a2 = +5;
  long int b = -48;
  short c = 15;

  s21_sprintf(str31, format, a1, a2, a, a1, a, a1, b, c);
  sprintf(str32, format, a1, a2, a, a1, a, a1, b, c);

  ck_assert_str_eq(str31, str32);
}
END_TEST

START_TEST(sprintf_unsigned) {
  char str33[100] = "";
  char str34[100] = "";

  const char format[] = "%u %10u %.5u %-10.8u %lu %hu";
  unsigned a = 50, a1 = 5;
  unsigned long b = 48;
  unsigned short c = 15;

  s21_sprintf(str33, format, a1, a, a, a, b, c);
  sprintf(str34, format, a1, a, a, a, b, c);

  ck_assert_str_eq(str33, str34);
}
END_TEST

START_TEST(sprintf_float) {
  char str35[100] = "";
  char str36[100] = "";

  const char format[] = "%f %+-f %5f %10.7f % 7f %f";
  float a = 17.53, a1 = -10.57565, b = 8;

  s21_sprintf(str35, format, a, a1, a, a, a, b);
  sprintf(str36, format, a, a1, a, a, a, b);

  ck_assert_str_eq(str35, str36);
}
END_TEST

START_TEST(sprintf_char) {
  char str37[100] = "";
  char str38[100] = "";

  const char format[] = "%c %-s %5s %10.7s %c";
  char c = 'Z';
  char *s = "Zenya";
  fflush(stdout);
  s21_sprintf(str37, format, c, s, s, s, c);
  sprintf(str38, format, c, s, s, s, c);

  ck_assert_str_eq(str37, str38);
}
END_TEST

START_TEST(sprintf_cases) {
  char str39[100] = "";
  char str40[100] = "";

  fflush(stdout);
  const char format[] = "%i %-10.5i %hi %%";
  int a = 123;
  short b = 123;

  s21_sprintf(str39, format, a, a, b);
  sprintf(str40, format, a, a, b);

  ck_assert_str_eq(str39, str40);
}
END_TEST

START_TEST(sscanf_int) {
  const char format[] = "%d %ld %hd";
  const char buff[] = "123 1234567 890";
  int a = 30;
  long b = 15;
  short s = 45, s1 = 45;
  int c = 30;
  long d = 15;

  s21_sscanf(buff, format, &a, &b, &s);
  sscanf(buff, format, &c, &d, &s1);

  ck_assert_int_eq(a, c);
  ck_assert_int_eq(b, d);
  ck_assert_int_eq(s, s1);
}
END_TEST

START_TEST(sscanf_unsigned) {
  const char format[] = "%u %lu %hu";
  const char buff[] = "-123 567 78";
  unsigned a = 30;
  unsigned long b = 15;
  unsigned short s = 45, s1 = 45;
  unsigned c = 30;
  unsigned long d = 15;

  s21_sscanf(buff, format, &a, &b, &s);
  sscanf(buff, format, &c, &d, &s1);

  ck_assert_int_eq(a, c);
  ck_assert_int_eq(b, d);
  ck_assert_int_eq(s, s1);
}
END_TEST

START_TEST(sscanf_float) {
  const char format[] = "%f %f";
  const char buff[] = "-12.3 567.67";
  float a = 30;
  float b = 15.6;
  float c = 30;
  float d = 15.6;

  s21_sscanf(buff, format, &a, &b);
  sscanf(buff, format, &c, &d);

  ck_assert_uint_eq(a, c);
  ck_assert_uint_eq(b, d);
}
END_TEST

START_TEST(sscanf_double) {
  const char format[] = "%lf %f";
  const char buff[] = "-12.3 567.67e-2";
  double a = 30;
  float b = 15.6;
  double c = 30;
  float d = 15.6;

  s21_sscanf(buff, format, &a, &b);
  sscanf(buff, format, &c, &d);

  ck_assert_uint_eq(a, c);
  ck_assert_uint_eq(b, d);
}
END_TEST

START_TEST(sscanf_char) {
  const char format[] = "%c %s";
  const char buff[] = "babangida";
  char a, b;
  char str_s[40];
  char str_s1[40];

  s21_sscanf(buff, format, &a, str_s);
  sscanf(buff, format, &b, str_s1);

  ck_assert_int_eq(a, b);
  ck_assert_str_eq(str_s, str_s1);
}
END_TEST

START_TEST(sscanf_hex) {
  const char format[] = "%lx %x";
  const char buff[] = "0xff -0x71fff";

  unsigned long a = 1234, b = 6789;
  unsigned int c = 123, d = 1239;

  s21_sscanf(buff, format, &a, &c);
  sscanf(buff, format, &b, &d);

  ck_assert_int_eq(a, b);
  ck_assert_int_eq(c, d);
}
END_TEST

START_TEST(sscanf_e) {
  const char format[] = "%le";
  const char buf[] = "2.435e-07";
  double s, s21;

  s21_sscanf(buf, format, &s21);
  sscanf(buf, format, &s);

  ck_assert_uint_eq(s, s21);
}
END_TEST

START_TEST(sscanf_return_count) {
  const char *format = "%d%f%c%p%d%ho";
  const char *buf = "546 qwe 9.8744e 0x7ffeed9834e1 34 000010";
  int a, a1;
  float f, f1;
  char c, c1;
  int qwe, qwe1;
  unsigned long b, b1;
  unsigned short o, o1;
  int s, s21;

  s = sscanf(buf, format, &a, &f, &c, &b, &qwe, &o);
  s21 = s21_sscanf(buf, format, &a1, &f1, &c1, &b1, &qwe1, &o1);

  ck_assert_int_eq(s, s21);
}
END_TEST

START_TEST(sscanf_oct) {
  const char format[] = "%5ho";
  const char *buf = "64215";
  unsigned short a = 010, a1 = 045;

  s21_sscanf(buf, format, &a);
  sscanf(buf, format, &a1);

  ck_assert_int_eq(a, a1);
}
END_TEST

START_TEST(sscanf_star) {
  const char format[] = "%*s %s";
  const char buf[] = "run run1";
  char a[150];
  char a1[150];

  s21_sscanf(buf, format, a);
  sscanf(buf, format, a1);

  ck_assert_str_eq(a, a1);
}
END_TEST

START_TEST(sscanf_percent) {
  const char format[] = "run%%%s";
  const char buf[] = "run run";
  char s[100];
  char s21[100];

  s21_sscanf(buf, format, s21);
  sscanf(buf, format, s);

  ck_assert_str_eq(s, s21);
}
END_TEST

START_TEST(sscanf_ptr) {
  const char format[] = "%p";
  const char buf[] = "0x7ffee8739347";
  void *str_ptr;
  void *str_ptr1;

  s21_sscanf(buf, format, &str_ptr);
  sscanf(buf, format, &str_ptr1);

  ck_assert_ptr_eq(str_ptr, str_ptr1);
}
END_TEST

START_TEST(sscanf_n) {
  const char format[] = "%*s %n";
  const char buf[] = "0x7ffee3845288";
  int s, s21;

  s21_sscanf(buf, format, &s21);
  sscanf(buf, format, &s);

  ck_assert_int_eq(s, s21);
}
END_TEST

START_TEST(sscanf_i) {
  const char format[] = "%i %hi";
  const char buf[] = "0x7ffee3 075";
  int s, s21;
  short int a, a1;

  s21_sscanf(buf, format, &s21, &a);
  sscanf(buf, format, &s, &a1);

  ck_assert_int_eq(s, s21);
  ck_assert_int_eq(a, a1);
}
END_TEST

int main(void) {
  Suite *s1 = suite_create("Core");
  TCase *tc1_1 = tcase_create("Core");
  SRunner *sr = srunner_create(s1);
  int nf;

  suite_add_tcase(s1, tc1_1);
  tcase_add_test(tc1_1, memchrTest);
  tcase_add_test(tc1_1, memcmpTest);
  tcase_add_test(tc1_1, memcpyTest);
  tcase_add_test(tc1_1, memmoveTest);
  tcase_add_test(tc1_1, memsetTest);
  tcase_add_test(tc1_1, strcatTest);
  tcase_add_test(tc1_1, strncatTest);
  tcase_add_test(tc1_1, strchrTest);
  tcase_add_test(tc1_1, strcmpTest);
  tcase_add_test(tc1_1, strncmpTest);
  tcase_add_test(tc1_1, strcpyTest);
  tcase_add_test(tc1_1, strncpyTest);
  tcase_add_test(tc1_1, strcspnTest);
  tcase_add_test(tc1_1, strerrorTest);
  tcase_add_test(tc1_1, strlenTest);
  tcase_add_test(tc1_1, strpbrkTest);
  tcase_add_test(tc1_1, strrchrTest);
  tcase_add_test(tc1_1, strspnTest);
  tcase_add_test(tc1_1, strstrTest);
  tcase_add_test(tc1_1, strtokTest);
  tcase_add_test(tc1_1, toUpperTest);
  tcase_add_test(tc1_1, toUpperTest1);
  tcase_add_test(tc1_1, toLowerTest);
  tcase_add_test(tc1_1, toLowerTest1);
  tcase_add_test(tc1_1, insertTest);
  tcase_add_test(tc1_1, insertTest1);
  tcase_add_test(tc1_1, insertTest2);
  tcase_add_test(tc1_1, trimTest);
  tcase_add_test(tc1_1, trimTest1);
  tcase_add_test(tc1_1, sprintf_int);
  tcase_add_test(tc1_1, sprintf_unsigned);
  tcase_add_test(tc1_1, sprintf_float);
  tcase_add_test(tc1_1, sprintf_char);
  tcase_add_test(tc1_1, sprintf_cases);
  tcase_add_test(tc1_1, sscanf_int);
  tcase_add_test(tc1_1, sscanf_unsigned);
  tcase_add_test(tc1_1, sscanf_float);
  tcase_add_test(tc1_1, sscanf_double);
  tcase_add_test(tc1_1, sscanf_char);
  tcase_add_test(tc1_1, sscanf_hex);
  tcase_add_test(tc1_1, sscanf_e);
  tcase_add_test(tc1_1, sscanf_return_count);
  tcase_add_test(tc1_1, sscanf_oct);
  tcase_add_test(tc1_1, sscanf_star);
  tcase_add_test(tc1_1, sscanf_percent);
  tcase_add_test(tc1_1, sscanf_ptr);
  tcase_add_test(tc1_1, sscanf_n);
  tcase_add_test(tc1_1, sscanf_i);

  srunner_run_all(sr, CK_ENV);
  nf = srunner_ntests_failed(sr);
  srunner_free(sr);

  return nf == 0 ? 0 : 1;
}
