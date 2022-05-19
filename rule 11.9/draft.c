union c_un
{
    long* pt1;
    bool* pt2;
}

union c_un cu1 = {0};       //#nodefect  //0的多种含义, 可以表示地址为0x0？
union c_un cu2 = {1};       //nodefect;