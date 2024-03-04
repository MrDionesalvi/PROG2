/* scrivere qui la vostra suite di test */

/* ad esempio: */
tests[0].s = "0";
tests[0].b = 10;
tests[0].res = 1;
tests[0].num = 0;

tests[1].s = "0";
tests[1].b = 1;
tests[1].res = 0;
tests[1].num = 0;

tests[2].s = "15NF";
tests[2].b = 36;
tests[2].res = 1;
tests[2].num = 53979;

tests[3].s = " 10";
tests[3].b = 10;
tests[3].res = 1;
tests[3].num = 10;

tests[4].s = " 10a3";
tests[4].b = 10;
tests[4].res = 1;
tests[4].num = 10;

tests[5].s = " 7a3";
tests[5].b = 6;
tests[5].res = 0;
tests[5].num = 0;

tests[6].s = "  -0012";
tests[6].b = 10;
tests[6].res = 1;
tests[6].num = -12;

tests[7].s = "  +2";
tests[7].b = 10;
tests[7].res = 1;
tests[7].num = 2;

tests[8].s = "0000200";
tests[8].b = 10;
tests[8].res = 1;
tests[8].num = 200;

tests[9].s = "A"; // CHECK(7)
tests[9].b = 11;
tests[9].res = 1;
tests[9].num = 10;

tests[10].s = "23"; //check(12)
tests[10].b = 3;
tests[10].res = 1;
tests[10].num = 2;

tests[11].s = "                 "; //
tests[11].b = 10;
tests[11].res = 0;
tests[11].num = 0;