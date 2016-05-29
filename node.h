#ifndef NODE_H
#define NODE_H
#include "surface.h"
#include <math.h>
//class Surface;
//std::ios_base::sync_with_stdio(false);
class Node
{
private:
    unsigned int common_index = 0;
    unsigned int x_index = 0;
    unsigned int y_index = 0;
    double k_adsorpion = 1;
    double k_desorpion = 100; //not used
    double k_migration = 10000;
    double v_adsorpion = 0;
    double v_desorpion = 0;
    double v_migration_all = 0;
    double v_migration_up = 0;
    double v_migration_left = 0;
    double v_migration_right = 0;
    double v_summ = 0;
    const double E_0 = 0.5;
    const double E_0_1 = 0.5;
    const double E_0_2 = 0.5;
    const double E_1_0 = 2.6;
    const double E_1_1 = 1.8;
    const double E_1_2 = 1.8;
    const double E_2_0 = 3.9;
    const double E_2_1 = 1.8;
    const double E_2_2 = 1.8;
    const int temperature = 1178;//K = 900C
    const double R = 8.661734e-5;//Эв/К
    const double RT = R * temperature;
    double delta_t_j = 0; //время пребывания ячейки в текущем состоянии
    std::vector <Node *> first_neighbors;
    std::vector <Node *> second_neighbors;

    int its_node_state; //состояние узла
public:
    Node():its_node_state(0) {}
    ~Node() {}
    inline unsigned int get_node_state() {return its_node_state;}
    inline void set_node_state(int new_state) {its_node_state = new_state;}
    inline void set_first_neighbors(Node * node) {first_neighbors.push_back(node);}
    inline void set_second_neighbors(Node *node) {second_neighbors.push_back(node);}
    inline std::vector <Node *> get_first_neighbors() {return first_neighbors;}
    inline std::vector<Node *> get_second_neighbors() {return second_neighbors;}
    int num_free_first_neighbors();
    inline unsigned int get_by_xy(const int x, const int y, const int N_line) //Возвращает нумерацию змейкой not used
    {
        return x * N_line + ((x % 2) ? (N_line - y - 1) : y);
    }
    void print_first_neighbors();
    inline double arrenius (double E)
    {
//        std::cout << k_migration << " * exp(-" << E << "/" << RT << ") = " << k_migration * exp((-1 * E)/RT) << std::endl;
        return k_migration * exp((-1 * E)/RT);
    }
    void velocity_calculation (); //расчет скоростей
    inline double get_v_adsorpion () {return v_adsorpion;}
    inline double get_v_desorpion () {return v_desorpion;}
    inline double get_v_migration () {return v_migration_all;}
    inline double get_v_summ () {return v_summ;}
    inline double get_delta_t_j() {return delta_t_j;}
    inline unsigned int get_x_index () {return x_index;}
    inline unsigned int get_y_index () {return y_index;}
    inline void set_x_index (unsigned int index) {x_index = index;}
    inline void set_y_index (unsigned int index) {y_index = index;}
    inline unsigned int get_common_index() {return common_index;}
    inline void set_common_index(unsigned int index) {common_index = index;}
    void migration ();
    void adsorption(unsigned int new_state);
    void set_delta_t_j ();

};

#endif // NODE_H
