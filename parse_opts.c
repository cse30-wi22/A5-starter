#include "poll_lookup.h"
/*
 * !!! DO NOT EDIT THIS FUNCTION !!!
 * parse_opts
 *
 * Arguments: argc, argv, pointer to filename, pointer to hash table size,
 *pointer to info flag,
 *            pointer to date string, pointer to search flag, pointer to search
 *parameter,
 *            pointer to search type
 *
 * Operation: parses argv for ALL the allowable flags
 *            -i sets info to 1 (0 otherwise)
 *            -t set the hash table size after converting the arguement to an
 *unsigned long
 *                >= MIN_TABLE_SIZE
 *            -d copies the date string to date
 *            copies the name of the file to filename
 * returns:   1 if success and 0 otherwise
 * !!! DO NOT EDIT THIS FUNCTION !!!
 */
int parse_opts(int argc, char *argv[], char **filename, unsigned long *size,
               int *info, char **date, char **del_date) {
  int opt;
  char *endptr;
  int fail = 0;
  extern int errno;

  opterr = 0;
  *filename = NULL;
  *date = NULL;
  *del_date = NULL;
  /*
    -i      info on whole table
    -t size tablesize
    -d date date in format "yyyy-mm-dd"
    -r date date to remove from table in format "yyyy-mm-dd"
   */
  while ((opt = getopt(argc, argv, "it:d:r:")) != -1) {
    switch (opt) {
    // Info flag
    case 'i':
      *info = 1;
      break;
    // Tablesize
    case 't':
      errno = 0;
      if (((*size = strtoul(optarg, &endptr, 10)) < MIN_TABLE_SIZE) ||
          (errno != 0) || (*endptr != '\0')) {
        fprintf(stderr, "%s: -t value must be equal or larger than %d\n",
                argv[0], MIN_TABLE_SIZE);
        fail = 1;
      }
      break;
    // Date string
    case 'd':
      *date = optarg;
      break;
    // Date string for removal
    case 'r':
      *del_date = optarg;
      break;
    case '?':
      fprintf(stderr, "%s: unknown option -%c\n", argv[0], optopt);
      fail = 1;
      break;
    default:
      fail = 1;
      break;
    }
  }

  *filename = argv[optind];
  if (*filename == NULL) {
    fprintf(stderr, "%s: filename is required\n", argv[0]);
    fail = 1;
  }
  if (*date == NULL) {
    fprintf(stderr, "%s: query date is required\n", argv[0]);
    fail = 1;
  }
  if (fail) {
    fprintf(stderr, "Usage: %s [-i] [-t tablesize] [-r datestring] [-d "
                    "datestring] filename\n",
            argv[0]);
  }

  return !fail;
}
