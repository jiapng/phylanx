// Copyright (c) 2018 Parsa Amini
// Copyright (c) 2018 Hartmut Kaiser
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <phylanx/config.hpp>
#include <phylanx/plugins/arithmetics/sum_operation.hpp>
#include <phylanx/plugins/arithmetics/statistics_impl.hpp>

#include <algorithm>
#include <functional>
#include <string>
#include <utility>
#include <vector>

///////////////////////////////////////////////////////////////////////////////
namespace phylanx { namespace execution_tree { namespace primitives
{
    ///////////////////////////////////////////////////////////////////////////
    namespace detail
    {
        struct statistics_sum_op
        {
            template <typename T>
            static constexpr T initial()
            {
                return T(0);
            }

            template <typename Iter, typename T>
            T operator()(Iter b, Iter e, T initial) const
            {
                return std::accumulate(b, e, initial, std::plus<T>());
            }
        };
    }

    ///////////////////////////////////////////////////////////////////////////
    match_pattern_type const sum_operation::match_data =
    {
        match_pattern_type{
            "sum",
            std::vector<std::string>{
                "sum(_1)", "sum(_1, _2)", "sum(_1, _2, _3)"},
            &create_sum_operation, &create_primitive<sum_operation>, R"(
            v, axis, keep_dim
            Args:

                v (vector or matrix) : a vector or matrix
                axis (optional, integer): a axis to sum along
                keep_dim (optional, boolean): keep dimension of input

            Returns:

            The sum of all values along the specified axis.)",
            true
        }
    };

    ///////////////////////////////////////////////////////////////////////////
    sum_operation::sum_operation(primitive_arguments_type&& operands,
            std::string const& name, std::string const& codename)
      : base_type(std::move(operands), name, codename)
    {
    }
}}}