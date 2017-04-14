/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: svalenti
 *
 * Created on April 5, 2017, 12:53 PM
 */

#include <cstdlib>
#include <iostream>
#include <boost/qvm/all.hpp>

using namespace std;
using namespace boost::qvm;

using qf = quat<float>;
using vf = vec<float, 3>;
using mf44 = mat<float, 4, 4>;

const float pi = 3.14159265359;
const float radians_per_degree = (2.0 * pi) / 360.0;

template <typename T>
void print_out(T& qvm_obj, string& msg) {
    string qvm_obj_str = to_string(qvm_obj);
    cout << msg << qvm_obj_str << '\n';
}

/*
 * 
 */
int main(int argc, char** argv) {
    
    vf vx{ 2.0, 0.0, 0.0 };
    vf vy{ 0.0, 3.0, 0.0 };
    vf vz{ 0.0, 0.0, 4.0 };
    
    float theta(90.0f * radians_per_degree);
   
    qf xrot, yrot, zrot;
    set_rotx(xrot, theta);
    set_roty(yrot, theta);
    set_rotz(zrot, theta);
    
    string str_xrot("quaternion xrot 90 deg = ");
    string str_yrot("quaternion yrot 90 deg = ");
    string str_zrot("quaternion zrot 90 deg = ");
    print_out(xrot, str_xrot);
    print_out(yrot, str_yrot);
    print_out(zrot, str_zrot);
    
    vf rotxx = xrot * vx;
    vf rotxy = xrot * vy;
    vf rotxz = xrot * vz;
    
    string str_rotxx("rotxx = ");
    string str_rotxy("rotxy = ");
    string str_rotxz("rotxz = ");
    print_out(rotxx, str_rotxx);
    print_out(rotxy, str_rotxy);
    print_out(rotxz, str_rotxz);
    
    vf rotzy_z = zrot * yrot * vz;
    string rotzy_z_str = to_string(rotzy_z);
    cout << "rotate about y axis then z axis (0,0,4) = " << rotzy_z_str << '\n';
    
    qf slerp_res = slerp(xrot, yrot, 0.5);
    string slerp_str = to_string(slerp_res);
    cout << "slerp result = " << slerp_str << '\n';
    
    vf xlat_v = { 1.0, 2.0, 3.0 };
    mf44 xlat_m = translation_mat(xlat_v);
    string xlat_m_str = to_string(xlat_m);
    cout << "xlat_m_str = " << xlat_m_str << '\n';
    
    return 0;
}

