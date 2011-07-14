///
/// Copyright (c) 2011 CNRS
/// Authors: Florent Lamiraux
///
///
// This file is part of hpp-model
// hpp-model is free software: you can redistribute it
// and/or modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation, either version
// 3 of the License, or (at your option) any later version.
//
// hpp-model is distributed in the hope that it will be
// useful, but WITHOUT ANY WARRANTY; without even the implied warranty
// of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// General Lesser Public License for more details.  You should have
// received a copy of the GNU Lesser General Public License along with
// hpp-model  If not, see
// <http://www.gnu.org/licenses/>.


#ifndef HPP_MODEL_JOINT_COMMON_HH
#define HPP_MODEL_JOINT_COMMON_HH

#include <jrl/mal/matrixabstractlayer.hh>
#include <KineoModel/kppProperty.h>
#include <KineoModel/kppJointComponent.h>

#include "hpp/model/fwd.hh"

KIT_PREDEF_CLASS(CkppDoubleProperty);
KIT_PREDEF_CLASS(CkwsJoint);
KIT_PREDEF_CLASS(CjrlJoint);

namespace hpp {
  namespace model {
    class Joint
    {
    public:
      ///
      /// \name Conversion between KineoWorks and Mal homogeneous Matrices
      /// @{
	
      ///
      /// \brief Conversion from KineoWorks to Matrix Abstraction Layer
      ///
      static matrix4d abstractMatrixFromCkitMat4(const CkitMat4& matrix);
	
      ///
      /// \brief Conversion from Matrix Abstraction Layer to KineoWorks
      ///
      static CkitMat4 CkitMat4MatrixFromAbstract(const matrix4d& matrix);
	
      ///
      ///@}
      ///

      ///
      /// \name Access to parent classes
      /// @{

      ///
      /// \brief Get shared pointer to CkppJointComponent part
      ///
      CkppJointComponentShPtr kppJoint() const;

      ///
      /// \brief Access to dynamic part of the joint.
      ///
      CjrlJoint* jrlJoint();

      ///
      /// \brief Const access to dynamic part of the joint.
      ///
      const CjrlJoint* jrlJoint() const;

      ///
      /// @}
      ///

      ///
      /// \name Kinematic chain
      /// @{ 
      ///
      /// \brief Get the parent joint
      ///
      virtual JointShPtr parentJoint() const;

      ///
      /// \brief Get the child joint at given rank
      ///
      virtual JointShPtr childJoint(unsigned int rank) const;

      ///
      /// \brief Add a child to the joint
      ///
      virtual void addChildJoint(JointShPtr joint);

      ///
      /// \brief Get number of child joints
      ///
      virtual unsigned int countChildJoints() const;
      ///
      /// @}
      ///

      ///
      /// \name Bounds of the degrees of freedom
      /// @{

      ///
      /// \brief Determine whether the degree of freedom of the joint is bounded
      ///
      /// \param dofRank Rank of the degree of freedom that is bounded
      /// \param bounded Whether the degree of freedom is bounded
      ///
      void isBounded(unsigned int dofRank, bool bounded);

      ///
      /// \brief Return whether the degree of freedom of the joint is bounded
      ///
      /// \param dofRank Rank of the degree of freedom that is bounded
      ///
      bool isBounded(unsigned int dofRank) const;

      ///
      /// \brief Get the lower bound of a given degree of freedom of the joint.
      ///
      /// \param dofRank Id of the dof in the joint
      ///
      virtual double lowerBound(unsigned int dofRank) const;
      
      ///
      /// \brief Get the upper bound of a given degree of freedom of the joint.
      ///
      ///\param dofRank Id of the dof in the joint
      ///
      virtual double upperBound(unsigned int dofRank) const;

      ///
      /// \brief Set the lower bound of a given degree of freedom of the joint.
      ///
      /// \param dofRank Id of the dof in the joint
      ///
      virtual void lowerBound(unsigned int dofRank, double lowerBound);

      ///
      /// \brief Set the upper bound of a given degree of freedom of the joint.
      ///
      /// \param dofRank Id of the dof in the joint
      ///
      virtual void upperBound(unsigned int dofRank, double upperBound);
      
      ///
      /// \brief Set the bounds of the degrees of freedom of the joint
      ///
      /// \param dofRank Rank of the degree of freedom that is bounded
      ///
      /// \param upperBound upper bound of this degree of freedom
      void bounds(unsigned int dofRank, const double& lowerBound,
		  const double& upperBound);

      ///
      /// \brief Set the velocity bounds of the degrees of freedom of the joint
      ///
      /// \param dofRank Rank of the degree of freedom that is bounded
      ///
      /// \param upperVelocityBound upper velocity bound of this deg. of freedom
      void velocityBounds(unsigned int dofRank,
			  const double& lowerVelocityBound,
			  const double& upperVelocityBound);
      
      ///
      /// @}
      ///
      ///
      /// \name Attached body
      /// @{

      ///
      /// \brief Attach a body to the joint
      ///
      void setAttachedBody(const BodyShPtr& inBody);

      ///
      /// \brief Get the body attached to the joint
      ///
      BodyShPtr attachedBody() const;

      ///
      /// @}
      ///

      ///
      /// \name CkppComponent properties
      /// @{
      ///

      void fillPropertyVector(std::vector<CkppPropertyShPtr>& outPropertyVector)
	const;
      // Mass
      static const CkppProperty::TPropertyID MASS_ID;
      static const std::string MASS_STRING_ID;

      // Local center of mass
      static const CkppProperty::TPropertyID COM_X_ID;
      static const std::string COM_X_STRING_ID;
      static const CkppProperty::TPropertyID COM_Y_ID;
      static const std::string COM_Y_STRING_ID;
      static const CkppProperty::TPropertyID COM_Z_ID;
      static const std::string COM_Z_STRING_ID;

      // Inertia matrix
      static const CkppProperty::TPropertyID INERTIA_MATRIX_XX_ID;
      static const std::string INERTIA_MATRIX_XX_STRING_ID;
      static const CkppProperty::TPropertyID INERTIA_MATRIX_YY_ID;
      static const std::string INERTIA_MATRIX_YY_STRING_ID;
      static const CkppProperty::TPropertyID INERTIA_MATRIX_ZZ_ID;
      static const std::string INERTIA_MATRIX_ZZ_STRING_ID;
      static const CkppProperty::TPropertyID INERTIA_MATRIX_XY_ID;
      static const std::string INERTIA_MATRIX_XY_STRING_ID;
      static const CkppProperty::TPropertyID INERTIA_MATRIX_XZ_ID;
      static const std::string INERTIA_MATRIX_XZ_STRING_ID;
      static const CkppProperty::TPropertyID INERTIA_MATRIX_YZ_ID;
      static const std::string INERTIA_MATRIX_YZ_STRING_ID;
      
      CkppDoublePropertyShPtr mass;
      CkppDoublePropertyShPtr comX;
      CkppDoublePropertyShPtr comY;
      CkppDoublePropertyShPtr comZ;
      CkppDoublePropertyShPtr inertiaMatrixXX;
      CkppDoublePropertyShPtr inertiaMatrixYY;
      CkppDoublePropertyShPtr inertiaMatrixZZ;
      CkppDoublePropertyShPtr inertiaMatrixXY;
      CkppDoublePropertyShPtr inertiaMatrixXZ;
      CkppDoublePropertyShPtr inertiaMatrixYZ;

      ///
      /// @}
      ///
      
    protected:
      Joint();
      /// \brief Create properties and store weak pointer
      ktStatus init(const JointWkPtr& weakPtr);
    private:
      JointWkPtr weakPtr_;
    }; // class Joint
  } // namespace model
} // namespace hpp
std::ostream& operator<<(std::ostream& os, const hpp::model::Joint& joint);

#endif // HPP_MODEL_JOINT_COMMON_HH
