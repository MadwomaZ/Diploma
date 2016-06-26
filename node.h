#ifndef NODE_H
#define NODE_H
#include "surface.h"
#include <math.h>
#include <cassert>
//class Surface;
//std::ios_base::sync_with_stdio(false);
class Node
{
private:
    Surface::host_state its_node_state; //состояние узла
    unsigned int common_index = 0;
    unsigned int x_index = 0;
    unsigned int y_index = 0;
public:
    static constexpr double k_adsorpion = 1e-5;
    static constexpr double k_desorpion = 100; //not used
    static constexpr double k_migration = 1000;
private:
    double v_adsorpion = 0;
    double v_desorpion = 0;
    double v_migration_all = 0;
    double v_migration[3] = {0, };//{right, left, up}
    double v_summ = 0;
public:
    //Чем больше Е, тем сложнее оторваться частице
    static constexpr double E_0 = 0.5;
    static constexpr double E_0_1 = 0.5;
    static constexpr double E_0_2 = 0.5;
    static constexpr double E_1_0 = 2.6;
    static constexpr double E_1_1 = 1.8;
    static constexpr double E_1_2 = 1.2;
    static constexpr double E_2_0 = 3.9;
    static constexpr double E_2_1 = 3.2;
    static constexpr double E_2_2 = 2.0;
private:
    static const int temperature = 1173;//K = 900C
    static constexpr double R =/* 8.6173303e-5; */ 8.661734e-5;//Эв/К
    static constexpr double RT = R * temperature;
public:
    static constexpr double V_0 = k_migration * exp((-1 * E_0)/RT);
    static constexpr double V_0_1 = k_migration * exp((-1 * E_0_1)/RT);
    static constexpr double V_0_2 = k_migration * exp((-1 * E_0_2)/RT);
    static constexpr double V_1_0 = k_migration * exp((-1 * E_1_0)/RT);
    static constexpr double V_1_1 = k_migration * exp((-1 * E_1_1)/RT);
    static constexpr double V_1_2 = k_migration * exp((-1 * E_1_2)/RT);
    static constexpr double V_2_0 = k_migration * exp((-1 * E_2_0)/RT);
    static constexpr double V_2_1 = k_migration * exp((-1 * E_2_1)/RT);
    static constexpr double V_2_2 = k_migration * exp((-1 * E_2_2)/RT);
private:
    double V_first[3][3] = {{V_0  , V_0_1, V_0_2},//[prev][next]
                            {V_1_0, V_1_1, V_1_2},
                            {V_2_0, V_2_1, V_2_2}};
    double V_second[5][5] = {{0.5/2, 0.4/2, 0.3/2, 0.2/2, 0.1/2}, //[prev][next]
                             {2.6/2, 1.8/2, 1.2/2, 0.8/2, 0.6/2},
                             {3.9/2, 3.2/2, 2.0/2, 1.6/2, 1.0/2},
                             {4.4/2, 3.7/2, 2.5/2, 2.1/2, 1.5/2},
                             {4.9/2, 4.2/2, 3.0/2, 2.6/2, 2.0/2}};
    double delta_t_j = 0; //время пребывания ячейки в текущем состоянии
    std::vector <Node *> first_neighbors;
    std::vector <Node *> second_neighbors;

public:
    Node():its_node_state(Surface::free_place) {}
    ~Node() {}
    inline Surface::host_state get_node_state() {return its_node_state;}
    inline void set_node_state(Surface::host_state new_state) {its_node_state = new_state;}
    inline void set_first_neighbors(Node * node) {first_neighbors.push_back(node);} //={right, left, up}
    inline void set_second_neighbors(Node *node) {second_neighbors.push_back(node);}
    inline std::vector <Node *> get_first_neighbors() {return first_neighbors;}
    inline std::vector<Node *> get_second_neighbors() {return second_neighbors;}
    int num_free_first_neighbors();
    inline unsigned int get_by_xy(const int x, const int y, const int N_line) //Возвращает нумерацию змейкой not used
    {
        return x * N_line + ((x % 2) ? (N_line - y - 1) : y);
    }
    void print_first_neighbors();
//    inline double arrenius (double E)
//    {
////        std::cout << k_migration << " * exp(-" << E << "/" << RT << ") = " << k_migration * exp((-1 * E)/RT) << std::endl;
//        return k_migration * exp((-1 * E)/RT);
//    }
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
    int migration();
    int adsorption(Surface::host_state new_state);
    void set_delta_t_j ();

};

#endif // NODE_H
