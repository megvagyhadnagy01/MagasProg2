/*

$ g++ future4.cpp -o future4 -lboost_system -lboost_filesystem -std=c++11
$ ./future42

 */

/**
 * @brief Gyors protók a FUTURE játékélmény felderítéséhez, kialakításához.
 *
 * @file future4.cpp
 * @author  Norbert Bátfai <nbatfai@gmail.com>
 * @version 0.0.1
 *
 * @section LICENSE
 *
 * Copyright (C) 2017 Norbert Bátfai, batfai.norbert@inf.unideb.hu
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * @section DESCRIPTION
 * FUTURE
 *
 */

#include <iostream>

#include <ctime>
#include <boost/date_time/gregorian/gregorian.hpp>

#include <boost/filesystem.hpp>
#include <boost/filesystem/fstream.hpp>
#include <numeric>

#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/graphviz.hpp>

#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/io.hpp>
#include <boost/numeric/ublas/operation.hpp>

#include <random>

typedef boost::adjacency_list < boost::listS, boost::vecS, boost::directedS,
        boost::property < boost::vertex_name_t, std::string,
        boost::property<boost::vertex_index2_t, int >> ,
        boost::property<boost::edge_weight_t, int >> CityGraph;

typedef boost::graph_traits<CityGraph>::vertex_descriptor CityGraphVertex;
typedef boost::property_map<CityGraph, boost::vertex_name_t>::type VertexNameMap;
typedef boost::property_map<CityGraph, boost::vertex_index2_t>::type VertexIndexMap;
typedef boost::graph_traits<CityGraph>::vertex_iterator VertexIter;
typedef boost::graph_traits <CityGraph>::adjacency_iterator AdjacencyIter;

typedef std::map <std::string, int> Preconds;
typedef Preconds Props;

class Player
{
    Props p;
    std::string role {"City/Debrecen/Életciklus/Született"};
    std::string prev_role;
    int age {0};
    int knowledge {0};

    std::default_random_engine rnd;
    std::uniform_int_distribution<int> udist {0, 3};

public:

    Player(boost::filesystem::path name, std::string role): role(role) {

        rnd.seed(std::random_device {}());

        boost::filesystem::path file(name);

        std::string key;
        int value {0};

        boost::filesystem::ifstream ifs {file};
        while ((ifs >> key >> value))
            p[key] = value;


        age = p["Külcsín/Kor/min"];
        knowledge = p["Belbecs/Tudás/min"];

    }

    void devel() {

        age += 300;
        knowledge += udist(rnd);

    }

    void level(CityGraph &city_graph,
               VertexNameMap &v2str,
               std::map <std::string, CityGraphVertex> &str2v,
               std::map <CityGraphVertex, Preconds> &v2preconds) {

        std::pair<AdjacencyIter, AdjacencyIter> ai =
            boost::adjacent_vertices(str2v[role], city_graph);


        int minout = std::numeric_limits<int>::max();
        std::vector<std::string> proles;
        for (; ai.first != ai.second; ++ai.first) {

            int outlimit = (v2preconds[*ai.first])["Külcsín/Kor/min"];

            if (outlimit && minout > outlimit)
                minout = outlimit;

            if (age > outlimit) {

                proles.push_back(v2str[*ai.first]);
            }
        }

        if (proles.size() > 0) {

            auto iter = proles.begin();
            std::uniform_int_distribution<int> udist(0, std::distance(proles.begin(), proles.end()) - 1);
            std::advance(iter, udist(rnd));

            prev_role = role;
            role = *iter;

            std::string born("City/Debrecen/Életciklus/Született");
            if (!born.compare(role) && born.compare(prev_role)) {

                age = 0;
            }

        }

    }


    std::string get_role() {
        return role;
    }

    void set_role(std::string role) {
        this->role = role;
    }
};


struct tm *next_calendar_day(struct tm *date)
{

    struct tm *real_date;

    ++date->tm_mday;

    time_t realepoch = std::mktime(date);
    real_date = std::gmtime(&realepoch);
    *date = *real_date;

    return date;
}

int get_freq(boost::filesystem::path file)
{
    int freq {0};

    boost::filesystem::ifstream ifs {file};
    ifs >> freq;

    return freq;
}

int sum_freq(std::map<std::string, int> &freq)
{
    int sum = std::accumulate(freq.begin(), freq.end(), 0,
    [](int total, std::pair<std::string, int> pair) {
        return total + pair.second;
    });

    return sum;
}

void read_city(boost::filesystem::path path, std::map <std::string, int> &freq)
{

    if (is_regular_file(path)) {

        std::string ext(".preconds");
        if (ext.compare(boost::filesystem::extension(path))) {
            freq[path.string()] = get_freq(path);
            std::cout << path.string() << " " << freq[path.string()] << std::endl;
        }


    } else if (is_directory(path))
        for (boost::filesystem::directory_entry & entry : boost::filesystem::directory_iterator(path))
            read_city(entry.path(), freq);

}


std::vector<std::string> load_tos(boost::filesystem::path file)
{

    std::vector<std::string> v;
    int freq {0};


    boost::filesystem::ifstream ifs {file};
    ifs >> freq;

    std::string s;
    while (ifs >> s) {
        v.push_back(s);
    }

    return v;
}


Preconds load_preconds(boost::filesystem::path name)
{

    boost::filesystem::path file(name);

    Preconds v;
    std::string key;
    int value {0};

    boost::filesystem::ifstream ifs {file};
    while ((ifs >> key >> value))
        v[key] = value;

    return v;
}

void add_vertices(CityGraph &city_graph, VertexNameMap &v2str, VertexIndexMap &v2idx,
                  std::map <std::string, CityGraphVertex> &str2v, std::map <std::string, int> &freq,
                  std::map <CityGraphVertex, Preconds> &v2preconds)
{

    int idx {0};
    for (const auto & pair : freq) {

        std::cout << "Vertex " << pair.first << " added" << std::endl;

        CityGraphVertex v = boost::add_vertex(city_graph);
        v2str[v] = pair.first;
        v2idx[v] = idx++;
        str2v[pair.first] = v;

        v2preconds[v] = load_preconds(pair.first + ".preconds");

        std::cout << pair.first << std::endl;
        for (const auto & p : v2preconds[v])
            std::cout << "   " << p.first << " " << p.second << " PRECONDS " << std::endl;

    }

}

void add_edges(CityGraph &city_graph,
               std::map <std::string, CityGraphVertex> &str2v, std::map <std::string, int> &freq)
{
    for (const auto & pair : freq) {

        boost::filesystem::path namefile(pair.first);

        std::vector<std::string> to_names = load_tos(namefile);

        to_names.push_back(namefile.string());

        for (const auto & name : to_names) {

            std::cout << "Edge " << pair.first << " -> " << name << " added" << std::endl;

            boost::add_edge(str2v[pair.first], str2v[name], 1, city_graph);
        }

    }

}

void print_graph(CityGraph &city_graph, VertexNameMap &v2str, std::string &city)
{

    std::fstream graph_log(city + ".dot" , std::ios_base::out);
    boost::write_graphviz(graph_log, city_graph, boost::make_label_writer(v2str));

}

void create_smatrix(CityGraph &city_graph, VertexNameMap &v2str, VertexIndexMap &v2idx,
                    std::map <std::string, CityGraphVertex> &str2v, boost::numeric::ublas::matrix<double> &m)
{

    for (std::pair<VertexIter, VertexIter> vi = boost::vertices(city_graph); vi.first != vi.second; ++vi.first) {

        int nof_outedges = boost::out_degree(*vi.first, city_graph);
        std::cout << "deg+(" << v2str[*vi.first] << ") = " << nof_outedges << std::endl;

        std::pair<AdjacencyIter, AdjacencyIter> ai =
            boost::adjacent_vertices(boost::vertex(*vi.first, city_graph), city_graph);

        for (; ai.first != ai.second; ++ai.first) {
            std::cout << v2idx[*ai.first] << " " << v2str[*ai.first] << std::endl;

            m(v2idx[*vi.first], v2idx[*ai.first]) = 1.0 / nof_outedges;

        }

    }

}

void create_dvector(CityGraph &city_graph, VertexNameMap &v2str, VertexIndexMap &v2idx,
                    std::map <std::string, int> &freq, int sum, boost::numeric::ublas::vector<double> &v)
{

    std::pair<VertexIter, VertexIter> vi;
    for (vi = boost::vertices(city_graph); vi.first != vi.second; ++vi.first) {

        double d = freq[v2str[*vi.first]];
        v(v2idx[*vi.first]) = d / (double)sum;

    }

}

void print_dvector(CityGraph &city_graph, VertexNameMap &v2str, VertexIndexMap &v2idx,
                   int sum, boost::numeric::ublas::vector<double> &v)
{

    std::pair<VertexIter, VertexIter> vi;
    for (vi = boost::vertices(city_graph); vi.first != vi.second; ++vi.first) {

        std::cout << v2str[*vi.first] << ": " << sum *v(v2idx[*vi.first]) << std::endl;

    }

}

void simul(std::vector<Player> &players,
           CityGraph &city_graph,
           VertexNameMap &v2str,
           std::map <std::string, CityGraphVertex> &str2v,
           std::map <CityGraphVertex, Preconds> &v2preconds)
{

    std::map <std::string, int> freq;

    for (auto & p : players) {

        p.devel();
        p.level(city_graph, v2str, str2v, v2preconds);


        ++freq[p.get_role()];
    }


    for (auto f : freq) {
        std::cout << f.first << " : " << std::string(f.second / 10000, '*') << " "  << f.second << std::endl;
    }
}

int
main()
{

    struct tm date;
    struct tm *tmpdate;

    boost::gregorian::date greta_birthday(2008, boost::gregorian::Mar, 11);

    std::string city_name {"Debrecen"};
    boost::filesystem::path city_path("City/" + city_name);
    std::map <std::string, int> freq;
    read_city(city_path, freq);

    int sum = sum_freq(freq);
    std::cout << sum << std::endl;

    std::vector<Player> players;

    std::cout << "Creating players..." << std::endl;
    int psum {0};
    for (const auto & pair : freq) {

        for (int i {0}; i < pair.second; ++i) {
            Player p {"Player/Routine", pair.first};
            players.push_back(p);
        }

        std::cout << (psum += pair.second) << "/" << sum << std::endl;
    }

    CityGraph city_graph;
    VertexNameMap v2str = boost::get(boost::vertex_name, city_graph);
    VertexIndexMap v2idx = boost::get(boost::vertex_index2, city_graph);
    std::map <std::string, CityGraphVertex> str2v;

    std::map <CityGraphVertex, Preconds> v2preconds;

    // add_vertices(city_graph, v2str, v2idx, str2v, freq);
    add_vertices(city_graph, v2str, v2idx, str2v, freq, v2preconds);
    add_edges(city_graph, str2v, freq);

    int nof_vertices = boost::num_vertices(city_graph);
    std::cout << "# edges: " << boost::num_edges(city_graph) << std::endl;;
    std::cout << "# vertices: " << nof_vertices << std::endl;;

    print_graph(city_graph, v2str, city_name);

    boost::numeric::ublas::matrix<double> smatrix(nof_vertices, nof_vertices, 0.0);

    create_smatrix(city_graph, v2str, v2idx, str2v, smatrix);

    std::cout << smatrix << std::endl;

    boost::numeric::ublas::vector<double> dvector(nof_vertices);
    create_dvector(city_graph, v2str, v2idx, freq, sum, dvector);

    std::cout << "sum:" << boost::numeric::ublas::sum(dvector) << " " << dvector << std::endl;
    print_dvector(city_graph, v2str, v2idx, sum, dvector);

    time_t now = std::time(NULL);
    tmpdate = std::gmtime(&now);
    date = *tmpdate;

    boost::numeric::ublas::vector<double> w(nof_vertices);

    int ticktock {0};
    do {

        simul(players, city_graph, v2str, str2v, v2preconds);
        std::cout << " ticktock " << (ticktock = (ticktock + 1) % 2) << std::endl;

        /*
            boost::numeric::ublas::axpy_prod(dvector, smatrix, w, true);
            if (boost::numeric::ublas::norm_2(dvector - w) < 0.00000001)
                break;
            dvector = w;
            std::cout << "sum:" << boost::numeric::ublas::sum(dvector) << " " << dvector << std::endl;
            std::cout << dvector *sum << std::endl;
            print_dvector(city_graph, v2str, v2idx, sum, dvector);
            */


        boost::gregorian::date n = boost::gregorian::date_from_tm(date);
        if (n.month() == greta_birthday.month()
                && n.day() == greta_birthday.day()) {
            std::cout << "Happy birthday, Gréta!" << std::endl;
            std::cout << std::asctime(&date) << std::endl;

        }

    } while (next_calendar_day(&date)->tm_year < 3000 - 1900);

}

