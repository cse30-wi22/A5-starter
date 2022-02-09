/*
 * CSE30 WI22 HW6
 * CSE30 username: cs30wi22cXX (TODO: Fill in)
 */

#include "poll_lookup.h"

/*
 * !!! DO NOT EDIT THIS FUNCTION !!!
 * main
 *
 * Arguments: argc, argv
 *
 * Operation: Main driver for the program, calls other funttions to:
 *            parse the options, allocate the hash table, load the table, print
 *out the table stats
 *            and make print population stats of the desired city/state
 * Returns:   EXIT_SUCCESS if all ok, EXIT_FAILURE otherwise
 * !!! DO NOT EDIT THIS FUNCTION !!!
 */
int main(int argc, char *argv[]) {
  node **table;
  unsigned long size = TABLE_SIZE;
  // name of csv file
  char *filename;
  int info = 0;

  // Indicates days we want stats for/to remove
  char *date = NULL;
  char *del_date = NULL;

  // Parse options
  if (!parse_opts(argc, argv, &filename, &size, &info, &date, &del_date)) {
    return EXIT_FAILURE;
  }

  // Allocate space for table
  if ((table = calloc(size, sizeof(node *))) == NULL) {
    fprintf(stderr, "%s: Unable to allocate space for hash table\n", argv[0]);
    return EXIT_FAILURE;
  }

  // Load records from file
  if (load_table(table, size, filename)) {
    return EXIT_FAILURE;
  }

  // Delete data first
  if (del_date) {
    char *stripped_date = strip_date(del_date);
    if (stripped_date) { // no malloc fail
      delete_date(table, size, stripped_date);
      free(stripped_date);
    } else {
      return EXIT_FAILURE;
    }
  }

  // Produce data for a single date
  if (date) {
    char *stripped_date = strip_date(date);
    if (stripped_date) { // no malloc fail
      print_date_stats(table, size, stripped_date);
      free(stripped_date);
    } else {
      return EXIT_FAILURE;
    }
  }

  // Print metadata
  if (info)
    print_info(table, size);

  // Clean up
  delete_table(table, size);

  return EXIT_SUCCESS;
}

/*
 * !!! DO NOT EDIT THIS FUNCTION !!!
 * hash
 *
 * Arguments: a null terminated string
 *
 * Operation: calculates a hash value for the string
 *
 * returns:   the hash value
 * !!! DO NOT EDIT THIS FUNCTION !!!
 */
unsigned long hash(char *str) {
  unsigned long hash = 0;
  unsigned int c;
#ifdef C_HASH
  while ((c = (unsigned char)*str++) != '\0') {
    hash = c + (hash << 6) + (hash << 16) - hash;
  }
#else
  while ((c = (unsigned char)*str++) != '\0') {
    hash = hashFun((unsigned long)c, hash);
  }
#endif
  return hash;
}

/*
 * node_lookup
 * Searches for the first node with this year, month, day, and hour
 * in this chain, and returns a pointer to it.
 *
 * Arguments: linked list chain pointer head, year, month, day, hour
 */
node *node_lookup(node *front, int year, int month, int day, int hour) {
  // TODO: Implement node_lookup
  return NULL;
}

/*
 * add_node
 * Adds a node with the provided data to the end of the given linked list.
 *
 * Arguments: linked list pointer head, year, month, day, hour, pm25, temp, iws
 * Return:  NULL    if there was an error
 *          the head of the chain otherwise
 */
node *add_node(node *front, int year, int month, int day, int hour, int pm25,
               int temp, float iws) {
  // TODO: Implement add_node
  return NULL;
}

/*
 * print_date_stats
 * Print the average stats for this date
 *
 * Arguments: pointer to hash table, hash table size, date as a string in the
 *form YYYY-MM-DD
 */
void print_date_stats(node **table, unsigned long size, char *datestr) {
  // TODO: Implement print_data_stats
  // Use the following formatting strings to print messages.
  printf("Unable to find any data for the date %s.\n", /* TODO */);
  printf("Minimum pm2.5: %d\tMaximum pm2.5: %d\tAverage pm2.5: %d\n",
         /* TODO */, /* TODO */, /* TODO */);
  printf("Minimum temp: %d\tMaximum temp: %d\tAverage temp: %d\n",
         /* TODO */, /* TODO */, /* TODO */);
  printf("Minimum iws: %f\tMaximum iws: %f\tAverage iws: %f\n",
         /* TODO */, /* TODO */, /* TODO */);
}

/*
 * load_table
 * Allocate memory for the hash table of node*s
 *
 * Arguments: pointer to hash table, hash table size, file name
 */
int load_table(node **table, unsigned long size, char *filename) {
  // TODO: Implement load_table
  return 0;
}

/*
 * delete_date
 * Delete all nodes associated with a given date of form YYYY-MM-DD
 * All leading zeros have already been removed in the date string,
 * so you do not have to worry about 2010-01-01 versus 2010-1-1.
 */
void delete_date(node **table, unsigned long size, char *datestr) {
  // TODO: Implement delete_date
}

/*
 * print_info
 *
 * Arguments: pointer to a hash table, number of elements
 */
void print_info(node **table, unsigned long size) {
  // TODO: Implement print_info
  printf("Table size: %lu\n", /* TODO */);
  printf("Total entries: %lu\n", /* TODO */);
  printf("Longest chain: %lu\n", /* TODO */);
  printf("Shortest chain: %lu\n", /* TODO */);
  printf("Empty buckets: %lu\n", /* TODO */);
}

/*
 * delete_table
 *
 * Arguments: pointer to hash table, hash table array size
 */
void delete_table(node **table, unsigned long size) {
  // TODO: Implement delete_table
}
