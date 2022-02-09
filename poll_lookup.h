/*
 * Constants
 */
#define LINE_SIZE 1024   // array size for reading with fgets
#define TABLE_SIZE 1873  // default hash table elements
#define MIN_TABLE_SIZE 3 // Smallest allowable hash table size
#define COL_YEAR 0       // 0-indexed columns for each param in the record
#define COL_MONTH 1
#define COL_DAY 2
#define COL_HOUR 3
#define COL_PM25 4
#define COL_TEMP 5
#define COL_IWS 6
#define MAX_SIZE_DATESTR 11 // Max size for date string YYYY-MM-DD (10+1 for \0)

/*
 * Headers you may need
 */
#include <ctype.h>
#include <errno.h>
#include <getopt.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <float.h>

/*
 * Hash table chains are of the following type
 */
typedef struct node {
  int year;
  int month; // 1-12
  int day;   // 1-31
  int hour;  // 0-23
  int pm25;  // NA = 0
  int temp;
  float iws;
  struct node *next;
} node;

extern void print_date_stats(node **table, unsigned long size, char *datestr);
extern node *node_lookup(node *front, int year, int month, int day, int hour);
extern node *add_node(node *front, int year, int month, int day, int hour,
                      int pm25, int temp, float iws);
extern void delete_date(node **table, unsigned long size, char *datestr);
extern unsigned long hash(char *str);
extern unsigned long hashFun(unsigned long c, unsigned long hash);
extern void print_info(node **table, unsigned long size);
extern int parse_opts(int argc, char *argv[], char **filename,
                      unsigned long *size, int *info, char **date,
                      char **del_date);
extern char *strip_date(char *datestr);
extern int load_table(node **table, unsigned long size, char *filename);
extern void delete_table(node **table, unsigned long size);
