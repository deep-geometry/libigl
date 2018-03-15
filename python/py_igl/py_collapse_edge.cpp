// This file is part of libigl, a simple c++ geometry processing library.
//
// Copyright (C) 2017 Sebastian Koch <s.koch@tu-berlin.de> and Daniele Panozzo <daniele.panozzo@gmail.com>
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.
m.def("collapse_edge", []
(
 int e,
 Eigen::MatrixXd& p_row,
 Eigen::MatrixXd& V,
 Eigen::MatrixXi& F,
 Eigen::MatrixXi& E,
 Eigen::MatrixXi& EMAP_m,
 Eigen::MatrixXi& EF,
 Eigen::MatrixXi& EI,
 int & e1,
 int & e2,
 int & f1,
 int & f2
)
{
  Eigen::RowVectorXd p = Eigen::Map<Eigen::RowVectorXd>(p_row.data(), p_row.size());
  Eigen::VectorXi EMAP = Eigen::Map<Eigen::VectorXi>(EMAP_m.data(), EMAP_m.size());
 return igl::collapse_edge(e, p, V, F, E, EMAP, EF, EI, e1, e2, f1, f2);
}, __doc_igl_collapse_edge,
py::arg("e"), py::arg("p"), py::arg("V"), py::arg("F"), py::arg("E"), py::arg("EMAP"), py::arg("EF"), py::arg("EI"), py::arg("e1"), py::arg("e2"), py::arg("f1"), py::arg("f2"));

m.def("collapse_edge", []
(
 int e,
 Eigen::MatrixXd& p_row,
 Eigen::MatrixXd& V,
 Eigen::MatrixXi& F,
 Eigen::MatrixXi& E,
 Eigen::MatrixXi& EMAP_m,
 Eigen::MatrixXi& EF,
 Eigen::MatrixXi& EI
)
{
  Eigen::RowVectorXd p = Eigen::Map<Eigen::RowVectorXd>(p_row.data(), p_row.size());
  Eigen::VectorXi EMAP = Eigen::Map<Eigen::VectorXi>(EMAP_m.data(), EMAP_m.size());
 return igl::collapse_edge(e, p, V, F, E, EMAP, EF, EI);
}, __doc_igl_collapse_edge,
py::arg("e"), py::arg("p"), py::arg("V"), py::arg("F"), py::arg("E"), py::arg("EMAP"), py::arg("EF"), py::arg("EI"));

m.def("collapse_edge", []
(
 std::function<void (const int, const Eigen::MatrixXd &, const Eigen::MatrixXi &, const Eigen::MatrixXi &, const Eigen::VectorXi &, const Eigen::MatrixXi &, const Eigen::MatrixXi &, double &, Eigen::RowVectorXd &)> & cost_and_placement,
 Eigen::MatrixXd& V,
 Eigen::MatrixXi& F,
 Eigen::MatrixXi& E,
 Eigen::MatrixXi& EMAP_m,
 Eigen::MatrixXi& EF,
 Eigen::MatrixXi& EI,
 std::set<std::pair<double, int> > & Q,
 std::vector<std::set<std::pair<double, int> >::iterator> & Qit,
 Eigen::MatrixXd& C
)
{
  Eigen::VectorXi EMAP = Eigen::Map<Eigen::VectorXi>(EMAP_m.data(), EMAP_m.size());
 return igl::collapse_edge(cost_and_placement, V, F, E, EMAP, EF, EI, Q, Qit, C);
}, __doc_igl_collapse_edge,
py::arg("cost_and_placement"), py::arg("V"), py::arg("F"), py::arg("E"), py::arg("EMAP"), py::arg("EF"), py::arg("EI"), py::arg("Q"), py::arg("Qit"), py::arg("C"));

m.def("collapse_edge", []
(
 std::function<void (const int, const Eigen::MatrixXd &, const Eigen::MatrixXi &, const Eigen::MatrixXi &, const Eigen::VectorXi &, const Eigen::MatrixXi &, const Eigen::MatrixXi &, double &, Eigen::RowVectorXd &)> & cost_and_placement,
 Eigen::MatrixXd& V,
 Eigen::MatrixXi& F,
 Eigen::MatrixXi& E,
 Eigen::MatrixXi& EMAP_m,
 Eigen::MatrixXi& EF,
 Eigen::MatrixXi& EI,
 std::set<std::pair<double, int> > & Q,
 std::vector<std::set<std::pair<double, int> >::iterator> & Qit,
 Eigen::MatrixXd& C,
 int & e,
 int & e1,
 int & e2,
 int & f1,
 int & f2
)
{
    const auto always_try = [](
    const Eigen::MatrixXd &                                         ,/*V*/
    const Eigen::MatrixXi &                                         ,/*F*/
    const Eigen::MatrixXi &                                         ,/*E*/
    const Eigen::VectorXi &                                         ,/*EMAP*/
    const Eigen::MatrixXi &                                         ,/*EF*/
    const Eigen::MatrixXi &                                         ,/*EI*/
    const std::set<std::pair<double,int> > &                        ,/*Q*/
    const std::vector<std::set<std::pair<double,int> >::iterator > &,/*Qit*/
    const Eigen::MatrixXd &                                         ,/*C*/
    const int                                                        /*e*/
    ) -> bool { return true;};
  const auto never_care = [](
    const Eigen::MatrixXd &                                         ,   /*V*/
    const Eigen::MatrixXi &                                         ,   /*F*/
    const Eigen::MatrixXi &                                         ,   /*E*/
    const Eigen::VectorXi &                                         ,/*EMAP*/
    const Eigen::MatrixXi &                                         ,  /*EF*/
    const Eigen::MatrixXi &                                         ,  /*EI*/
    const std::set<std::pair<double,int> > &                        ,   /*Q*/
    const std::vector<std::set<std::pair<double,int> >::iterator > &, /*Qit*/
    const Eigen::MatrixXd &                                         ,   /*C*/
    const int                                                       ,   /*e*/
    const int                                                       ,  /*e1*/
    const int                                                       ,  /*e2*/
    const int                                                       ,  /*f1*/
    const int                                                       ,  /*f2*/
    const bool                                                  /*collapsed*/
    )-> void { };
  Eigen::VectorXi EMAP = Eigen::Map<Eigen::VectorXi>(EMAP_m.data(), EMAP_m.size());
 return igl::collapse_edge(cost_and_placement, always_try, never_care, V, F, E, EMAP, EF, EI, Q, Qit, C, e, e1, e2, f1, f2);
}, __doc_igl_collapse_edge,
py::arg("cost_and_placement"), py::arg("V"), py::arg("F"), py::arg("E"), py::arg("EMAP"), py::arg("EF"), py::arg("EI"), py::arg("Q"), py::arg("Qit"), py::arg("C"), py::arg("e"), py::arg("e1"), py::arg("e2"), py::arg("f1"), py::arg("f2"));

