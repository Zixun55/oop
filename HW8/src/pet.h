#ifndef PET_H
#define PET_H
class Pet{
    public:
        Pet(){
            _name = "none";
            _weight = 0;
        }

        Pet(std::string const & kind, std::string const & name, double const weight)
        :_kind(kind),_name(name),_weight(weight) {
            ++_amount;
        }

        Pet(Pet const & other)
        :_kind(other._kind),_name(other._name),_weight(other._weight) {
            ++_amount;
        }

        virtual ~Pet() {
            --_amount;
        }

        virtual void feed() = 0;

        std::string kind() const {
            return _kind;
        }

        std::string name() const {
            return _name;
        }

        double weight() const {
            return _weight;
        }

        static int amount() {
            return _amount;
        }
    protected:
        void addweight(double a){
            _weight += a;
        }
    private:
        std::string _name;
        double _weight;
        std::string _kind;
        static int _amount;
};
int Pet::_amount = 0;
#endif