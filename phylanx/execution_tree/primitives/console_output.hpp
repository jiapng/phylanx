//  Copyright (c) 2017-2018 Hartmut Kaiser
//
//  Distributed under the Boost Software License, Version 1.0. (See accompanying
//  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#if !defined(PHYLANX_PRIMITIVES_CONSOLE_OUTPUT_NOV_07_2017_1150AM)
#define PHYLANX_PRIMITIVES_CONSOLE_OUTPUT_NOV_07_2017_1150AM

#include <phylanx/config.hpp>
#include <phylanx/execution_tree/primitives/base_primitive.hpp>
#include <phylanx/execution_tree/primitives/primitive_component_base.hpp>

#include <hpx/lcos/future.hpp>

#include <memory>
#include <string>
#include <vector>

namespace phylanx { namespace execution_tree { namespace primitives
{
    class console_output
      : public primitive_component_base
      , public std::enable_shared_from_this<console_output>
    {
    public:
        static match_pattern_type const match_data;

        console_output() = default;

        console_output(primitive_arguments_type&& operands,
            std::string const& name, std::string const& codename);

    private:
        hpx::future<primitive_argument_type> eval(
            primitive_arguments_type const& operands,
            primitive_arguments_type const& args,
            eval_context ctx) const override;
    };

    PHYLANX_EXPORT primitive create_console_output(hpx::id_type const& locality,
        primitive_arguments_type&& operands,
        std::string const& name = "", std::string const& codename = "");
}}}

#endif


