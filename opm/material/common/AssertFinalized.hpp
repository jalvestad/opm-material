// -*- mode: C++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*-
// vi: set et ts=4 sw=4 sts=4:
/*
  This file is part of the Open Porous Media project (OPM).

  OPM is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 2 of the License, or
  (at your option) any later version.

  OPM is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with OPM.  If not, see <http://www.gnu.org/licenses/>.

  Consult the COPYING file in the top-level source directory of this
  module for the precise wording of the license and the list of
  copyright holders.
*/
/*!
 * \file
 * \copydoc Opm::AssertFinalized
 */
#ifndef OPM_MATERIAL_ASSERT_FINALIZED_HPP
#define OPM_MATERIAL_ASSERT_FINALIZED_HPP

#include <type_traits>
#include <cassert>
#include <memory>

namespace Opm {

/*!
 * \brief Default implementation for asserting finalization of parameter objects.
 *
 */
class AssertFinalized
{
#if OPM_CHECK_PARAM_FINALIZED
    bool finalized_;
#endif

protected:
    /*!
     * \brief The default constructor.
     */
    AssertFinalized()
#if OPM_CHECK_PARAM_FINALIZED
        : finalized_( false )
#endif
    {
    }

    void assertFinalized_() const
    {
#if OPM_CHECK_PARAM_FINALIZED
        assert(finalized_);
#endif
    }

public:
    /*!
     * \brief Mark the object as finalized.
     */
    void finalize()
    {
#if OPM_CHECK_PARAM_FINALIZED
        finalized_ = true;
#endif
    }
};

} // namespace Opm
#endif
