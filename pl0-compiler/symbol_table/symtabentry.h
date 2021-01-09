enum {st_var = 1, st_const = 2, st_proc = 4};

class SymTabEntry {
    public:
        SymTabEntry(const int = -1, const int = -1);
        int type; // type of entry
        int val; // value (e.g. procedure number)
};