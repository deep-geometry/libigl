// This file is part of libigl, a simple c++ geometry processing library.
//
// Copyright (C) 2017 Sebastian Koch <s.koch@tu-berlin.de> and Daniele Panozzo <daniele.panozzo@gmail.com>
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.
// COMPLETE BINDINGS ========================


m.def("hsv_to_rgb", []
(
  const Eigen::MatrixXd& H
)
{
  Eigen::MatrixXd R;
  igl::hsv_to_rgb(H, R);
  return R;
}, __doc_igl_hsv_to_rgb,
py::arg("H"));





// INCOMPLETE BINDINGS ========================


//m.def("hsv_to_rgb", []
//(
//  T * hsv,
//  T * rgb
//)
//{
//  return igl::hsv_to_rgb(hsv, rgb);
//}, __doc_igl_hsv_to_rgb,
//py::arg("hsv"), py::arg("rgb"));

//m.def("hsv_to_rgb", []
//(
//  T & h,
//  T & s,
//  T & v,
//  T & r,
//  T & g,
//  T & b
//)
//{
//  return igl::hsv_to_rgb(h, s, v, r, g, b);
//}, __doc_igl_hsv_to_rgb,
//py::arg("h"), py::arg("s"), py::arg("v"), py::arg("r"), py::arg("g"), py::arg("b"));

