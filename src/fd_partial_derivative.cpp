#include "fd_partial_derivative.h"

void fd_partial_derivative(
  const int nx,
  const int ny,
  const int nz,
  const double h,
  const int dir,
  Eigen::SparseMatrix<double> & D)
{
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here
  int x_diff = 0, y_diff = 0, z_diff = 0;
  if (dir == 0) {
  	x_diff = 1;
  	
  }
  else if (dir == 1) {
  	y_diff = 1;
  }
  else if (dir == 2) {
  	z_diff = 1;
  }
  D = Eigen::SparseMatrix<double>((nx-x_diff)*(ny-y_diff)*(nz-z_diff), nx*ny*nz);
  for(int i = 0; i < nx - x_diff; i++) 
  {
    for(int j = 0; j < ny - y_diff; j++)
    {
      for(int k = 0; k < nz - z_diff; k++)
      {
        // Convert subscript to index
        const auto ind = i + nx*(j + k * ny);
        const auto ind_next = (x_diff + nx*(y_diff + z_diff * ny));
        D.insert(ind, ind) = -1;
        D.insert(ind, ind_next) = 1;
      }
    }
  }
  ////////////////////////////////////////////////////////////////////////////
}
