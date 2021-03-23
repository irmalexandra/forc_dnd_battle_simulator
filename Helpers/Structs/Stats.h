#ifndef FORC_PA_5_STATS_H
#define FORC_PA_5_STATS_H

struct baseStats {
    std::string name = "";
    std::string type= "unchanged from base_Stats";
    int life_min = 0;
    int life_max = 0;
    int str_min = 0;
    int str_max = 0;
    int int_min = 0;
    int int_max = 0;
};

struct baseIndividualStats{
    std::string name = "";
    std::string type = "unchanged from base_Stats";
    std::string gender = "";
    int life = 0;
    int strength= 0;
    int intelligence= 0;
    bool unnatural = false;
    int disquiet = 0;
    int fear = 0;
    int traumatism = 0;
    int terror = 0;

};

struct Range {
    Range(){
    }

    Range(int min, int max){
        this->min = min;
        this->max = max;
    };

    friend std::ostream& operator<< (std::ostream& out, Range range){
        out << range.min << "-" << range.max;
        return out;
    };

    int min = 0;
    int max = 0;
};
#endif //FORC_PA_5_STATS_H
