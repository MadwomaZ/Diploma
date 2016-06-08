#ifndef SURFACE_H
#define SURFACE_H
#include <iostream>
#include <array>
#include <vector>
#include <QVector>
#include <math.h>
#include "generator.h"

class Node;

//template<unsigned int number_of_nodes_in_x, unsigned int number_of_nodes_in_y>
class Surface
{
private:
    unsigned int number_of_nodes_in_x;
    unsigned int number_of_nodes_in_y;
    int all_nodes = 0;
    int all_free_nodes = 0;//здесь вычесть те, что мы исключаем из расчета
    int common_state = 0;
    double k_adsorpion_surface = 1;
    double k_desorpion_surface = 100;
    double k_migration_surface = 1000;
    double v_adsorpion_surface = 0;
    double v_desorpion_surface = 0;
    double v_migration_surface = 0;
    double v_summ_surface = 0;
    double total_time = 0;
    std::vector <double> all_delta_t_j;
    std::vector <std::vector <Node *> > its_surface;
public:
    //для графика адсорбции
    QVector<double> all_time; //все выбранные delta_t_j
    //отношение количества занятых частиц к общему количеству свободных мест в момент времени из all_time
    QVector<double> concentration;
    enum host_state {free_place = 0, substance1 = 1, substance2 = 2, substance3, do_not_use = 9};
    Surface();
    ~Surface();
    std::vector<std::vector<host_state> > getStates();
    Surface (unsigned int x, unsigned int y);
    inline unsigned int get_number_of_nodes_in_x () const {return number_of_nodes_in_x;}
    inline unsigned int get_number_of_nodes_in_y () const {return number_of_nodes_in_y;}
    void set_number_of_nodes_in_x (int x);
    void set_number_of_nodes_in_y (int y);
    inline unsigned int get_all_free_nodes () const {return all_free_nodes;}
    void set_all_free_nodes ();
    inline unsigned int get_all_nodes () const {return all_nodes;}
    void set_all_nodes ();
    void init_surface ();
    void print_surface ();
    inline int get_common_state () const { return common_state; }
    inline int set_common_state (int state) { common_state = state; return state; }
    unsigned int get_boundary_conditions (int i, int size) const;
    void set_first_neighbors (Node *node, int array_i, int array_j);
    void set_second_neighbors (Node *node, int array_i, int array_j);
    void set_all_first_neighbors ();
    void set_all_second_neighbors ();
    Node * get_element_in_surface (int i, int j);
    Node * get_element_by_common_index (unsigned int index);
    void adsorption (host_state new_state);
    void desorption ();
    void initial_distribution (unsigned int amount_of_particles, host_state new_state);
    void migration ();
    void velocity_calculation();
    void selection_process_for_node ();
    void selection_process_for_surface();
    void set_all_delta_t_j();
    void set_all_velocity_calculation();
    Node * select_node();
};

#endif // SURFACE_H
