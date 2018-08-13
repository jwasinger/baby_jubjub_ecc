/*    
    copyright 2018 to the baby_jubjub_ecc Authors

    This file is part of baby_jubjub_ecc.

    baby_jubjub_ecc is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    baby_jubjub_ecc is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with baby_jubjub_ecc.  If not, see <https://www.gnu.org/licenses/>.
*/


#include <cassert>
#include <memory>

#include <libsnark/gadgetlib1/gadget.hpp>

#ifndef BABY_JUBJUB_CPP
#define BABY_JUBJUB_CPP
#endif



namespace libsnark {

template<typename FieldT>
class eddsa : public gadget<FieldT> {

private:
    /* no internal variables */
public:

    pb_variable<FieldT> a;
    pb_variable<FieldT> d;


    //input variables 
    pb_variable<FieldT> pk_x;
    pb_variable<FieldT> pk_y;
    pb_variable_array<FieldT> A;
    pb_variable<FieldT> b_x;
    pb_variable<FieldT> b_y;
    pb_variable_array<FieldT> H;
    pb_variable_array<FieldT> S;
    pb_variable<FieldT> r_x;
    pb_variable<FieldT> r_y;
    pb_variable<FieldT> s_x;
    pb_variable<FieldT> s_y;

    //intermeidate variables 

    pb_variable_array<FieldT> lhs_x;

    pb_variable_array<FieldT> lhs_y;
    pb_variable_array<FieldT> rhs_mul_x;
    pb_variable_array<FieldT> rhs_mul_y;

    pb_variable<FieldT> rhs_x;
    pb_variable<FieldT> rhs_y;

    std::shared_ptr<isOnCurve<FieldT>> jubjub_isOnCurve1;
    std::shared_ptr<isOnCurve<FieldT>> jubjub_isOnCurve2;

    std::shared_ptr<pointAddition<FieldT>> jubjub_pointAddition;
    std::shared_ptr<pointMultiplication<FieldT>> jubjub_pointMultiplication_lhs;
    std::shared_ptr<pointMultiplication<FieldT>> jubjub_pointMultiplication_rhs;


    eddsa(protoboard<FieldT> &pb,
                   //const pb_linear_combination_array<FieldT> &bits,
                   const pb_variable<FieldT> &a, const pb_variable<FieldT> &d,
                   const pb_variable<FieldT> &pk_x, const pb_variable<FieldT> &pk_y,
                   const pb_variable<FieldT> &b_x, const pb_variable<FieldT> &b_y,
                   const pb_variable<FieldT> &r_x, const pb_variable<FieldT> &r_y,
                   const pb_variable_array<FieldT> &H, const pb_variable_array<FieldT> &S
                   );

    void generate_r1cs_constraints();
    void generate_r1cs_witness();
};

}
#include <eddsa.tcc>

