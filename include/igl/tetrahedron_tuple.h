// This file is part of libigl, a simple c++ geometry processing library.
//
// Copyright (C) 2017 Zhongshi Jiang <zhongshi@cims.nyu.edu>
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.
#ifndef IGL_TETTUPLEITERATOR_H
#define IGL_TETTUPLEITERATOR_H

#include <igl/igl_inline.h>
#include <Eigen/Core>

namespace igl
{
  // TetTupleIterator - Fake half-edge for fast and easy navigation
  // on tetrahedral meshes with tet_tet_adjacency.
  // 3D analogue for triangle_tuple.
  // Recommend read and understand triangle_tuple first.
  //
  // Note: this is different to classical Half Edge as in OpenVolumeMesh.
  //    Instead, it follows cell-tuple in [Brisson, 1989]
  //    "Representing geometric structures in d dimensions: topology and order."
  //    This class can achieve local navigation similar to OpenVolumeMesh
  //    But the logic behind each atom operation is different.
  //
  // Each tuple contains information on (tet, face, edge, vertex)
  //    and encoded by (tet, face, edge \in {0,1,2}, bool along)
  //
  // Inputs:
  //    (ti, fi, ei, along) as detailed above.
  //    T #T by 3 list of "faces"
  //    TT #T by 3 list of triangle-triangle adjacency.
  //    TTif #T by 3 list of TT inverse w.r.t face.
  //    TTie #T by 3 list of TT inverse w.r.t edge.
  //        For TT and TTi, refer to "tetrahedron_tetrahedron_adjacency.h"
  // Usages:
  //    tet_tuple_get_{vert/edge/face/tet} returns the
  //      {from-vertex id / *local* edge id/ *local* face id / tet id}
  //      associated with the represented half edge.
  //
  //    tet_tuple_switch_{vert/edge/face/tet} switches to another half edge
  //      that differes in only one v/e/f/t information.
  //
  //    tet_tuple_next_in_one_ring switch to next half edge
  //      in one-ring of the from vertex with proper handling of boundary.
  //
  //    triangle_tuple_is_on_boundary determines whether the current encoded
  //      half edge is on boundary.
  //
  //    triangle_tuples_equal is only a wrapper comparing the (t, f,e,a) tuple


  template<typename DerivedT, typename DerivedTT,
           typename DerivedTTif, typename DerivedTTie>
  IGL_INLINE void tet_tuple_switch_vert(
      int &ti, int &fi, int &ei, bool &along,
      const Eigen::MatrixBase<DerivedT> &T,
      const Eigen::MatrixBase<DerivedTT> &TT,
      const Eigen::MatrixBase<DerivedTTif> &TTif,
      const Eigen::MatrixBase<DerivedTTie> &TTie
  );

  template<typename DerivedT, typename DerivedTT,
           typename DerivedTTif, typename DerivedTTie>
  IGL_INLINE void tet_tuple_switch_edge(
      int &ti, int &fi, int &ei, bool &along,
      const Eigen::MatrixBase<DerivedT> &T,
      const Eigen::MatrixBase<DerivedTT> &TT,
      const Eigen::MatrixBase<DerivedTTif> &TTif,
      const Eigen::MatrixBase<DerivedTTie> &TTie
  );

  template<typename DerivedT, typename DerivedTT,
           typename DerivedTTif, typename DerivedTTie>
  IGL_INLINE void tet_tuple_switch_face(
      int &ti, int &fi, int &ei, bool &along,
      const Eigen::MatrixBase<DerivedT> &T,
      const Eigen::MatrixBase<DerivedTT> &TT,
      const Eigen::MatrixBase<DerivedTTif> &TTif,
      const Eigen::MatrixBase<DerivedTTie> &TTie
  );

  template<typename DerivedT, typename DerivedTT,
           typename DerivedTTif, typename DerivedTTie>
  IGL_INLINE void tet_tuple_switch_tet(
      int &ti, int &fi, int &ei, bool &along,
      const Eigen::MatrixBase<DerivedT> &T,
      const Eigen::MatrixBase<DerivedTT> &TT,
      const Eigen::MatrixBase<DerivedTTif> &TTif,
      const Eigen::MatrixBase<DerivedTTie> &TTie
  );

  template<typename DerivedT, typename DerivedTT,
           typename DerivedTTif, typename DerivedTTie>
  IGL_INLINE int tet_tuple_get_vert(
      int ti, int fi, int ei, bool along,
      const Eigen::MatrixBase<DerivedT> &T,
      const Eigen::MatrixBase<DerivedTT> &TT,
      const Eigen::MatrixBase<DerivedTTif> &TTif,
      const Eigen::MatrixBase<DerivedTTie> &TTie
  );

  template<typename DerivedT,
           typename DerivedTT,
           typename DerivedTTif,
           typename DerivedTTie>
  IGL_INLINE int tet_tuple_get_edge(
      int ti, int fi, int ei, bool along,
      const Eigen::MatrixBase<DerivedT> &T,
      const Eigen::MatrixBase<DerivedTT> &TT,
      const Eigen::MatrixBase<DerivedTTif> &TTif,
      const Eigen::MatrixBase<DerivedTTie> &TTie
  );

  template<typename DerivedT,
           typename DerivedTT,
           typename DerivedTTif,
           typename DerivedTTie>
  IGL_INLINE int tet_tuple_get_face(
      int ti, int fi, int ei, bool along,
      const Eigen::MatrixBase<DerivedT> &T,
      const Eigen::MatrixBase<DerivedTT> &TT,
      const Eigen::MatrixBase<DerivedTTif> &TTif,
      const Eigen::MatrixBase<DerivedTTie> &TTie
  );

  template<typename DerivedT,
           typename DerivedTT,
           typename DerivedTTif,
           typename DerivedTTie>
  IGL_INLINE int tet_tuple_get_tet(
      int ti, int fi, int ei, bool along,
      const Eigen::MatrixBase<DerivedT> &T,
      const Eigen::MatrixBase<DerivedTT> &TT,
      const Eigen::MatrixBase<DerivedTTif> &TTif,
      const Eigen::MatrixBase<DerivedTTie> &TTie
  );

  template<typename DerivedT,
           typename DerivedTT,
           typename DerivedTTif,
           typename DerivedTTie>
  IGL_INLINE bool tet_tuple_next_in_one_ring(
      int &ti, int &fi, int &ei, bool &along,
      const Eigen::MatrixBase<DerivedT> &T,
      const Eigen::MatrixBase<DerivedTT> &TT,
      const Eigen::MatrixBase<DerivedTTif> &TTif,
      const Eigen::MatrixBase<DerivedTTie> &TTie
  );

  template<typename DerivedT,
           typename DerivedTT,
           typename DerivedTTif,
           typename DerivedTTie>
  IGL_INLINE bool tet_tuple_is_on_boundary(
      int ti, int fi, int ei, bool along,
      const Eigen::MatrixBase<DerivedT> &T,
      const Eigen::MatrixBase<DerivedTT> &TT,
      const Eigen::MatrixBase<DerivedTTif> &TTif,
      const Eigen::MatrixBase<DerivedTTie> &TTie
  );

  IGL_INLINE bool tet_tuples_equal(
      int t1, int f1, int e1, bool rev1,
      int t2, int f2, int e2, bool rev2
  );
}

#ifndef IGL_STATIC_LIBRARY
#  include "tetrahedron_tuple.cpp"
#endif
#endif //EXAMPLE_HALFFACEITERATOR_H
