void Rule11_9_example_25(void)
{
    enum myEnum *cePtr = NULL;                              //#nodefect#TS1
    PINT cArr1[2] = {(void *)NULL_VAL, null_val};           //#nodefect#TS1
    int *cArr2[3] = {NULL, NULL, NULL};                     //#nodefect#TS1
    int *cArr3[2] = {(int *)(NULL_VAL), (int *)(NULL_VAL)}; //#nodefect#TS1
    int *cArr4[2][2] = {NULL, NULL, NULL, NULL};            //#nodefect#TS1
    int *cArr5[5] = {0};                                    //#fpdefect#SATW-4406#TS1
    PINT cArr6[3] = {0, 0, 0};                              //#fpdefect#SATW-4406#TS1
    int *cArr7[3] = {NULL_VAL, NULL_VAL};                   //#fpdefect#SATW-4406#TS1
    int *cArr8[2][2][3] = {0, 0, 0};                        //#fpdefect#SATW-4406#TS1
}

/*
 * Assign literal 0LL or 0 to enum and array member with pointer type.
 */
void Rule11_9_example_35(void)
{
    enum myEnum *nePtr = NULL_VAL;                              //#defect#TS1
    PINT32 nArr1[2] = {(void *)null, 0};                        //#defect#TS1
    int32_t *nArr2[5] = {(void *)0, 0};                         //#defect#TS1
    int *nArr3[3] = {(void *)0};                                //#defect#TS1
    PINT32 nArr4[3] = {(void *)0, 0, 0};                        //#defect#TS1
    int *nArrr5[2][2] = {(void *)0, 0, 0};                      //#defect#TS1
    int *nArrr6[2][2][2] = {(void *)0, 0, (void *)NULL_VAL, 0}; //#defect#TS1
}

