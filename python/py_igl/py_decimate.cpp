// This file is part of libigl, a simple c++ geometry processing library.
//
// Copyright (C) 2017 Zhongshi Jiang <jiangzs@nyu.edu>
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.

m.def("decimate", [](
    const Eigen::MatrixXd & V,
    const Eigen::MatrixXi & F,
    const size_t max_m,
    Eigen::MatrixXd & U,
    Eigen::MatrixXi & G,
    Eigen::MatrixXi & J_m,
    Eigen::MatrixXi & I_m) {
      Eigen::VectorXi I = Eigen::Map<Eigen::VectorXi>(I_m.data(), I_m.size());
      Eigen::VectorXi J = Eigen::Map<Eigen::VectorXi>(J_m.data(), J_m.size());
      return igl::decimate(V,F,max_m, U,G,J,I);
    }
);
 m.def("decimate", [] (
    const Eigen::MatrixXd & V,
    const Eigen::MatrixXi & F,
    const size_t max_m,
    Eigen::MatrixXd & U,
    Eigen::MatrixXi & G,
    Eigen::MatrixXi & J_m) {
      Eigen::VectorXi J = Eigen::Map<Eigen::VectorXi>(J_m.data(), J_m.size());       return igl::decimate(V,F,max_m,U,G,J);
    }
 );
  m.def("decimate", [] (
    const Eigen::MatrixXd & V,
    const Eigen::MatrixXi & F,
    const std::function<void(
      const int              /*e*/,
      const Eigen::MatrixXd &/*V*/,
      const Eigen::MatrixXi &/*F*/,
      const Eigen::MatrixXi &/*E*/,
      const Eigen::VectorXi &/*EMAP*/,
      const Eigen::MatrixXi &/*EF*/,
      const Eigen::MatrixXi &/*EI*/,
      double &               /*cost*/,
      Eigen::RowVectorXd &   /*p*/
      )> & cost_and_placement,
    const std::function<bool(
      const Eigen::MatrixXd &                                         ,/*V*/
      const Eigen::MatrixXi &                                         ,/*F*/
      const Eigen::MatrixXi &                                         ,/*E*/
      const Eigen::VectorXi &                                         ,/*EMAP*/
      const Eigen::MatrixXi &                                         ,/*EF*/
      const Eigen::MatrixXi &                                         ,/*EI*/
      const std::set<std::pair<double,int> > &                        ,/*Q*/
      const std::vector<std::set<std::pair<double,int> >::iterator > &,/*Qit*/
      const Eigen::MatrixXd &                                         ,/*C*/
      const int                                                       ,/*e*/
      const int                                                       ,/*e1*/
      const int                                                       ,/*e2*/
      const int                                                       ,/*f1*/
      const int                                                        /*f2*/
      )> & stopping_condition,
    Eigen::MatrixXd & U,
    Eigen::MatrixXi & G,
    Eigen::MatrixXi & J_m,
    Eigen::MatrixXi & I_m) {
      Eigen::VectorXi I = Eigen::Map<Eigen::VectorXi>(I_m.data(), I_m.size());       Eigen::VectorXi J = Eigen::Map<Eigen::VectorXi>(J_m.data(), J_m.size());       return igl::decimate(V,F,cost_and_placement, stopping_condition, U,G,J,I);
    }
  );

 m.def("decimate", [] (
    const Eigen::MatrixXd & V,
    const Eigen::MatrixXi & F,
    const std::function<void(
      const int              /*e*/,
      const Eigen::MatrixXd &/*V*/,
      const Eigen::MatrixXi &/*F*/,
      const Eigen::MatrixXi &/*E*/,
      const Eigen::VectorXi &/*EMAP*/,
      const Eigen::MatrixXi &/*EF*/,
      const Eigen::MatrixXi &/*EI*/,
      double &               /*cost*/,
      Eigen::RowVectorXd &   /*p*/
      )> & cost_and_placement,
    const std::function<bool(
      const Eigen::MatrixXd &                                         ,/*V*/
      const Eigen::MatrixXi &                                         ,/*F*/
      const Eigen::MatrixXi &                                         ,/*E*/
      const Eigen::VectorXi &                                         ,/*EMAP*/
      const Eigen::MatrixXi &                                         ,/*EF*/
      const Eigen::MatrixXi &                                         ,/*EI*/
      const std::set<std::pair<double,int> > &                        ,/*Q*/
      const std::vector<std::set<std::pair<double,int> >::iterator > &,/*Qit*/
      const Eigen::MatrixXd &                                         ,/*C*/
      const int                                                       ,/*e*/
      const int                                                       ,/*e1*/
      const int                                                       ,/*e2*/
      const int                                                       ,/*f1*/
      const int                                                        /*f2*/
      )> & stopping_condition,
    const std::function<bool(
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
      )> & pre_collapse,
    const std::function<void(
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
      )> & post_collapse,
    Eigen::MatrixXd & U,
    Eigen::MatrixXi & G,
    Eigen::MatrixXi & J_m,
    Eigen::MatrixXi & I_m) {
      Eigen::VectorXi I = Eigen::Map<Eigen::VectorXi>(I_m.data(), I_m.size());       Eigen::VectorXi J = Eigen::Map<Eigen::VectorXi>(J_m.data(), J_m.size());       return igl::decimate(V,F,cost_and_placement, stopping_condition, pre_collapse, post_collapse, U,G,J,I);
    }
 );

 m.def("decimate", [] (
    const Eigen::MatrixXd & V,
    const Eigen::MatrixXi & F,
    const std::function<void(
      const int              /*e*/,
      const Eigen::MatrixXd &/*V*/,
      const Eigen::MatrixXi &/*F*/,
      const Eigen::MatrixXi &/*E*/,
      const Eigen::VectorXi &/*EMAP*/,
      const Eigen::MatrixXi &/*EF*/,
      const Eigen::MatrixXi &/*EI*/,
      double &               /*cost*/,
      Eigen::RowVectorXd &   /*p*/
      )> & cost_and_placement,
    const std::function<bool(
      const Eigen::MatrixXd &                                         ,/*V*/
      const Eigen::MatrixXi &                                         ,/*F*/
      const Eigen::MatrixXi &                                         ,/*E*/
      const Eigen::VectorXi &                                         ,/*EMAP*/
      const Eigen::MatrixXi &                                         ,/*EF*/
      const Eigen::MatrixXi &                                         ,/*EI*/
      const std::set<std::pair<double,int> > &                        ,/*Q*/
      const std::vector<std::set<std::pair<double,int> >::iterator > &,/*Qit*/
      const Eigen::MatrixXd &                                         ,/*C*/
      const int                                                       ,/*e*/
      const int                                                       ,/*e1*/
      const int                                                       ,/*e2*/
      const int                                                       ,/*f1*/
      const int                                                        /*f2*/
      )> & stopping_condition,
    const std::function<bool(
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
      )> & pre_collapse,
    const std::function<void(
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
      )> & post_collapse,
    const Eigen::MatrixXi & E,
    const Eigen::VectorXi & EMAP,
    const Eigen::MatrixXi & EF,
    const Eigen::MatrixXi & EI,
    Eigen::MatrixXd & U,
    Eigen::MatrixXi & G,
    Eigen::MatrixXi & J_m,
    Eigen::MatrixXi & I_m) {
      Eigen::VectorXi I = Eigen::Map<Eigen::VectorXi>(I_m.data(), I_m.size());       Eigen::VectorXi J = Eigen::Map<Eigen::VectorXi>(J_m.data(), J_m.size());       return igl::decimate(V,F,cost_and_placement, stopping_condition, pre_collapse, post_collapse,
      E, EMAP, EF,EI, U,G,J,I);
    });