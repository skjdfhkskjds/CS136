// A module for an int sequence ADT

// This is an opaque structure definition
struct sequence;

// NOTE: All of the following functions REQUIRE:
//       pointers to a sequence (e.g., seq) are not NULL


// sequence_create() returns a pointer to a new (empty) sequence
struct sequence *sequence_create(void);


// sequence_length(seq) returns the number of items in seq
int sequence_length(const struct sequence *seq);


// sequence_clear(seq) removes all items from seq
// effects: seq is modified
void sequence_clear(struct sequence *seq);


// sequence_item_at(seq, pos) returns the item in seq at the given pos
// requires: 0 <= pos < length(seq)
int sequence_item_at(const struct sequence *seq, int pos);


// sequence_insert_at(seq, pos, val) inserts a new item with value val
//   at position pos in seq
//   (changing the position of elements at position >= pos)
// requires: and 0 <= pos <= length(seq)
// effects: seq is modified
void sequence_insert_at(struct sequence *seq, int pos, int val);


// sequence_remove_at(seq, pos) removes the item at position pos in seq
//   and returns the removed value
//   (changing the position of elements > pos)
// requires: 0 <= pos < length(seq)
// effects: seq is modified
int sequence_remove_at(struct sequence *seq, int pos);


// sequence_print(seq) prints out the items in seq
//   using the format: "[length] item1 item2 ... item_last\n"
//   or "[empty]\n"
// effects: prints out a message
void sequence_print(const struct sequence *seq);
