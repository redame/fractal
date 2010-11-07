/* Author: Vladimir Belikov
 *
 * This file is part of Fractal Library.
 *
 * Fractal Library is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Fractal Library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with Fractal Libray.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef MIN_H
#define MIN_H

#include "../Predicates.h"

namespace FL { namespace Predicates {

/*! \class Min
  * \brief Minimum of the time series segment
  *
  * Arguments:
  *  - args[0] -- IndexedName
  */
class Min : public Predicate
{
public:
    //! Default constructor
    Min()
    {
        m_name = "Min";
    }

    //! Call operator
    virtual const GVariant& operator()(Patterns::CheckContext& context, PredicateArgs& args)
    {
        if (args.size() == 0)
        {
            GError(GCritical, m_name, 0, EInvalidTermArgs);
            return m_result = 0.0;
        }

        std::vector<double> vec;
        context.ts->getTSByIndex(vec, 0);

        double result = 10e10; // maximum!
        FL::ParseTreeNode *node;

        std::vector<GVariant*>::const_iterator arg;
        for_each_(arg, args)
        {
            node = **arg;
            if (node == NULL)
            {
                GError(GWarning, m_name, 0, "NULL node passed");
                continue;
            }
            for (int i = node->tsBegin; i <= node->tsEnd + 1; i++)
                if (vec[i] < result)
                    result = vec[i];
        }
        return m_result = result;
    }
};


} } // namespaces

#endif // MIN_H
