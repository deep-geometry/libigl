m.def("seam_edges", []
(
  const Eigen::MatrixXd& V,
  const Eigen::MatrixXd& TC,
  const Eigen::MatrixXi& F,
  const Eigen::MatrixXi& FTC
)
{
  Eigen::MatrixXi seams;
  Eigen::MatrixXi boundaries;
  Eigen::MatrixXi foldovers;
  igl::seam_edges( V, TC, F, FTC, seams, boundaries, foldovers);
  return std::make_tuple(seams, boundaries, foldovers);
}, __doc_igl_seam_edges, py::arg("V"), py::arg("TC"), py::arg("F"), py::arg("FTC")); 
