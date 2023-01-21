template <class T>
class Range{
    private:
        T start, end;
    public:
        Range(){}
        Range(const T& start, const T& end){
            this->start = start; this->end = end;
        }
        ~Range(){}

        int GetStart() const {
            return start;
        }

        int GetEnd() const {
            return end;
        }
};