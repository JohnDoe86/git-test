/* Copyright (c) 2022 Synopsys, Inc. All rights reserved worldwide. */

/*{
 ANALYSIS_OPTS+=["--codexm"; "$PWD$/../CERT-FIO06-C.cxm"];
}*/

/*
 * Test cases for CERT-FIO06-C:
 * Create files with appropriate access permissions.
 */

#include <stdio.h>
#include <fcntl.h> // O_CREAT, O_WRONLY
#include <stdlib.h> // errno_t

// Cases from standard document

void nonCompliant1()
{
    char *file_name = "file.txt";
    FILE *fp;

    fp = fopen(file_name, "w");  //#defect#CERT FIO06-C
    if (!fp)
    {
        /* Handle error */
    }
}

void compliant1()
{
    char *file_name = "file.txt";
    FILE *fp;

    errno_t res = fopen_s(&fp, file_name, "wx");  //#nodefect#CERT FIO06-C
    if (res != 0) {
    /* Handle error */
    }
}

void nonCompliant2()
{
    char *file_name = "file.txt";
    int fd;

    fd = open(file_name, O_CREAT | O_WRONLY);  //#defect#CERT FIO06-C
    /* Access permissions were missing */

    if (fd == -1){
    /* Handle error */
    }
}

void compliant2()
{
    char *file_name = "file.txt";
    int file_access_permissions = 0666;

    int fd = open(file_name, O_CREAT | O_WRONLY, file_access_permissions);  //#nodefect#CERT FIO06-C
    if (fd == -1){
        /* Handle error */
    }
}

// End of standard document.

void compliant3()
{
    char *file_name = "file.txt";
    FILE *fp;

    /* This case is non-compliant on POSIX, but it's compliant on Windows because Windows doesn't
     * support the "u" parameter. So not report to avoid FPs.
     */
    errno_t res = fopen_s(&fp, file_name, "uwx");  //#nodefect#CERT FIO06-C
    if (res != 0) {
    /* Handle error */
    }
}

void nonCompliant3(int dirfd)
{
    char *file_name = "file.txt";
    int fd;

    fd = openat(dirfd, file_name, O_CREAT | O_WRONLY);  //#defect#CERT FIO06-C
    /* Access permissions were missing */

    if (fd < 0){
        /* Handle error */
    }
}

void compliant4(int dirfd)
{
    char *file_name = "file.txt";
    int file_access_permissions = 0666;

    int fd = openat(dirfd, file_name, O_CREAT | O_WRONLY, file_access_permissions);  //#nodefect#CERT FIO06-C
    if (fd < 0){
        /* Handle error */
    }
}
