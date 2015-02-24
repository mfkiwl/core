/*
 * Copyright 2011 Scientific Computation Research Center
 *
 * This work is open source software, licensed under the terms of the
 * BSD license as described in the LICENSE file in the top-level directory.
 */

#ifndef DWR_HIERARCHIC_H
#define DWR_HIERARCHIC_H

/** \file dwrHierarchic.h
  * \brief Hierarchic field node distribution and shape functions */

namespace apf {
class FieldShape;
}

namespace dwr {

/** \brief get hierarchic shape functions of some polynomial order
  * \details only first and second order so far */
apf::FieldShape* getHierarchic(int order);

}

#endif