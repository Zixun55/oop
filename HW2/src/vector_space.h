#include<iostream>

double *add(double v[],int dim_v,double u[],int dim_u){
        if(dim_u != dim_v || dim_v <= 0 || dim_u <= 0){
                throw std::string("undefined.");
        }
        double *add_w = new double[dim_v];
        for(int i = 0;i < dim_v ;i++){
                add_w[i] = v[i] + u[i];
        }
        return add_w;
}
double *scale(double v[],int dim_v,double a){
        if(dim_v <= 0){
                throw std::string("undefined.");
        }
        double *scale_w = new double[dim_v];
        for(int i = 0;i < dim_v ;i++){
                scale_w[i] = v[i] * a;
        }
        return scale_w;
}
