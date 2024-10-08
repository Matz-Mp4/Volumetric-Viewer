#include "../../include/math/Transforamation.hpp"
#include <cmath>
/*
    float data [] = {
        0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0,
    };
 */

Matrix4 Transformation::translation(float x, float y, float z) {
    float data [] = {
        1.0, 0.0, 0.0, x,
        0.0, 1.0, 0.0, y,
        0.0, 0.0, 1.0, z,
        0.0, 0.0, 0.0, 1.0,
    };
    return Matrix4(data);
}


Matrix4 Transformation::scaling(float x, float y, float z) {
    float data [] = {
          x, 0.0, 0.0, 0.0,
        0.0,   y, 0.0, 0.0,
        0.0, 0.0,   z, 0.0,
        0.0, 0.0, 0.0, 1.0,
    };
    return Matrix4(data);
}


Matrix4 Transformation::rotation_x(float angle) {
    float angle_cos = cos(angle);
    float angle_sin=  sin(angle);
    float data [] = {
          1.0,       0.0,        0.0, 0.0,
          0.0, angle_cos, -angle_sin, 0.0,
          0.0, angle_sin,  angle_cos, 0.0,
          0.0,       0.0,        0.0, 1.0,
      };
      return Matrix4(data);
}

Matrix4 Transformation::rotation_y(float angle) {

 float angle_cos = cos(angle);
  float angle_sin=  sin(angle);
  
  float data [] = {
         angle_cos, 0.0, angle_sin, 0.0,
               0.0, 1.0,       0.0, 0.0,
        -angle_sin, 0.0, angle_cos, 0.0,
               0.0, 0.0,       0.0, 1.0
    };
    return Matrix4(data);
}

Matrix4 Transformation::rotation_z(float angle) {
  float angle_cos = cos(angle);
  float angle_sin=  sin(angle);
  
  float data [] = {
        angle_cos, -angle_sin, 0.0, 0.0,
        angle_sin,  angle_cos, 0.0, 0.0,
              0.0,        0.0, 1.0, 0.0,
              0.0,        0.0, 0.0, 1.0,
    };
    return Matrix4(data);
}

//https://en.wikipedia.org/wiki/Rotation_matrix
Matrix4 Transformation::rotation(float angle, Vector4 axis) {
    float angle_cos = cos(angle);
    float angle_sin=  sin(angle);

    Vector4 axis_norm = axis.normalize();
    float x2 = axis_norm.x * axis_norm.x;
    float y2 = axis_norm.y * axis_norm.y;
    float z2 = axis_norm.z * axis_norm.z;
    float x_y = axis_norm.x * axis_norm.y;
    float x_z = axis_norm.x * axis_norm.z;
    float y_z = axis_norm.y * axis_norm.z;


    float data [] = {
                        x2 * (1 - angle_cos) + angle_cos,   x_y * (1 - angle_cos) - axis_norm.z * angle_sin,  x_z * (1 - angle_cos) + axis_norm.y * angle_sin,  0.0,
         x_y * (1 - angle_cos) + axis_norm.z * angle_sin,                  y2 * (1 - angle_cos) + angle_cos,  y_z * (1 - angle_cos) - axis_norm.x * angle_sin,  0.0,
        x_z * ( 1 - angle_cos) - axis_norm.y * angle_sin,  y_z * (1 - angle_cos) + axis_norm.x * angle_sin ,                 z2 * (1 - angle_cos) + angle_cos,  0.0,
                                                     0.0,                                                0.0,                                             0.0,  1.0
    };
    return Matrix4(data);
}
