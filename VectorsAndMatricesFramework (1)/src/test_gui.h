/**
 * This file implements our GUI. Since we only need one function, we don't create
 * a class for it.
 */

// Include this file only once when compiling:
#pragma once

// Include ImGui files:
#include "imgui.h"
#include "imgui_cg1_helpers.h"

// Include Math files:
#include "math/Vec4f.h"
#include "math/Mat4f.h"

/**
 * Generates a GUI to test the Vec4f and Mat4f implementation.
 *
 * Due to the Intermediate Mode GUI of the used GUI library ImGui, this has to
 * be called in every frame. (see https://de.wikipedia.org/wiki/Immediate_Mode_GUI)
 *
 * Since the parameters are given as reference (see '&' after the Type), changes
 * of to parameters will directly change the value of the original variable.
 */

void drawOurCG1TestGui(Vec4f& vectorA, Vec4f& vectorB, Mat4f& matrixA, Mat4f& matrixB){
    ImVec4 darkTextColor = ImVec4(0.5,0.5,0.5,1.0);

    ImGui::NewFrame();

    /* Create the 1st window to input values for vectorA, vectorB, matrixA and matrixB: */
    {
        // Setup the initial window pos and size:
        ImGui::SetNextWindowPos(ImVec2(10,10) /*, ImGuiCond_Once*/);
        ImGui::SetNextWindowSize(ImVec2(260,560) /*, ImGuiCond_Once*/);

        ImGui::Begin("Input Vectors and Matrices");

        // Make input for vectorA:
        ImGui::Text("Vec4f vectorA =");
        ImGui::Separator();
        ImGuiCG1::DragVec4f("vectorA", &vectorA.x, true);
        ImGui::Separator();
        ImGui::NewLine();

        // Make input for vectorB:
        ImGui::Separator();
        ImGui::Text("Vec4f vectorB =");
        ImGui::Separator();
        ImGuiCG1::DragVec4f("vectorB", &vectorB.x, true);
        ImGui::Separator();
        ImGui::NewLine();

        // Make input for matrixA:
        ImGui::Separator();
        ImGui::Text("Mat4f matrixA =");
        ImGui::Separator();
        ImGuiCG1::DragMat4f("matrixA", matrixA.data, true);
        ImGui::Separator();
        ImGui::NewLine();

        // Make input for matrixB:
        ImGui::Separator();
        ImGui::Text("Mat4f matrixB =");
        ImGui::Separator();
        ImGuiCG1::DragMat4f("matrixB", matrixB.data, true);
        ImGui::Separator();
        ImGui::NewLine();

        // Creates the reset button:
        if (ImGui::Button("Reset")){
            vectorA = Vec4f(1.f, 0.f, 0.f, 0.f);
            vectorB = Vec4f(0.f, 1.f, 0.f, 0.f);
            matrixA = Mat4f();
            matrixB = Mat4f();
        }

        ImGui::End();
    }

    /* Create the 2nd window to test vector functions */
    {
        // Setup the initial window pos and size:
        ImGui::SetNextWindowPos(ImVec2(280,10) /*, ImGuiCond_Once*/);
        ImGui::SetNextWindowSize(ImVec2(260,560) /*, ImGuiCond_Once*/);

        ImGui::Begin("Tests: Vector Functions");

        // Print length of both vectors:
        ImGui::Text("Length:");
        ImGui::Separator();
        ImGuiCG1::TextFloat("vectorA.length() returns:", vectorA.length());
        ImGuiCG1::TextFloat("vectorB.length() returns:",vectorB.length());
        ImGui::Separator();
        ImGui::NewLine();

        // Print length of both vectors:
        ImGui::Text("Distance:");
        ImGui::Separator();
        ImGuiCG1::TextFloat("vectorA.distanceTo(vectorB):", vectorA.distanceTo(vectorB));
        ImGui::Separator();
        ImGui::NewLine();

        // Show normalized vectors:
        ImGui::Separator();
        ImGui::Text("Normalization:");
        ImGui::Separator();
        Vec4f aNormalized = vectorA.normalized();
        ImGui::TextColored(darkTextColor, "vectorA.normalized() returns:");
        ImGuiCG1::DragVec4f("aNormalized", &aNormalized.x, false);
        ImGui::TextColored(darkTextColor, "vectorB.normalized() returns:");
        Vec4f bNormalized = vectorB.normalized();
        ImGuiCG1::DragVec4f("bNormalized", &bNormalized.x, false);
        ImGui::Separator();
        ImGui::NewLine();

        // Show dot product of vectors:
        ImGui::Separator();
        ImGui::Text("Dot Product:");
        ImGui::Separator();
        float aDotB = vectorA.dot(vectorB);
        ImGuiCG1::TextFloat("vectorA.dot(vectorB) returns:", aDotB);
        float bDotA = vectorB.dot(vectorA);
        ImGuiCG1::TextFloat("vectorB.dot(vectorA) returns:", bDotA);
        ImGui::Separator();
        ImGui::NewLine();

        // Show cross product of vectors:
        ImGui::Separator();
        ImGui::Text("Cross Product:");
        ImGui::Separator();
        Vec4f aCrossB = vectorA.cross(vectorB);
        ImGui::TextColored(darkTextColor, "vectorA.cross(vectorB) returns:");
        ImGuiCG1::DragVec4f("aCrossB", &aCrossB.x, false);
        Vec4f bCrossA = vectorB.cross(vectorA);
        ImGui::TextColored(darkTextColor, "vectorB.cross(vectorA) returns:");
        ImGuiCG1::DragVec4f("bCrossA", &bCrossA.x, false);
        ImGui::Separator();

        ImGui::End();
    }

    /* Create the 3rd window to test vector operators: */
    {
        // Setup the initial window pos and size:
        ImGui::SetNextWindowPos(ImVec2(550,10) /*, ImGuiCond_Once*/);
        ImGui::SetNextWindowSize(ImVec2(260,560) /*, ImGuiCond_Once*/);

        ImGui::Begin("Tests: Vector Operators");

        // Comparison Operators (==, !=):
        ImGui::Text("Comparison:");
        ImGui::Separator();
        ImGuiCG1::TextBool("vectorA == vectorB returns:", vectorA == vectorB);
        ImGuiCG1::TextBool("vectorA != vectorB returns:", vectorA != vectorB);
        ImGui::Separator();
        ImGui::NewLine();

        // Arithmetic Operators (*, /) with scalars:
        ImGui::Separator();
        ImGui::Text("Scalar Arithmetic:");
        ImGui::Separator();
        Vec4f AMultS = vectorA * 2.0f;
        ImGui::TextColored(darkTextColor, "vectorA * 2.0f returns:");
        ImGuiCG1::DragVec4f("vectorA * scalar", &AMultS.x);
        Vec4f ADivideS = vectorA / 3.0f;
        ImGui::TextColored(darkTextColor, "vectorA / 3.0f returns:");
        ImGuiCG1::DragVec4f("vectorA / scalar", &ADivideS.x);
        ImGui::Separator();
        ImGui::NewLine();

        // Arithmetic Operators (+,-) with vectors:
        ImGui::Separator();
        ImGui::Text("Vector Arithmetic:");
        ImGui::Separator();
        Vec4f aPlusB = vectorA + vectorB;
        ImGui::TextColored(darkTextColor, "vectorA + vectorB returns:");
        ImGuiCG1::DragVec4f("vectorA + vectorB", &aPlusB.x);
        Vec4f aMinusB = vectorA - vectorB;
        ImGui::TextColored(darkTextColor, "vectorA - vectorB returns:");
        ImGuiCG1::DragVec4f("vectorA - vectorB", &aMinusB.x);
        ImGui::Separator();
        ImGui::End();
    }


    /* Create the 4th window to test Mat4f operators: */
    {
        // Setup the initial window pos and size:
        ImGui::SetNextWindowPos(ImVec2(820,10) /*, ImGuiCond_Once*/);
        ImGui::SetNextWindowSize(ImVec2(260,560) /*, ImGuiCond_Once*/);

        // matrixA * vectorA:
        ImGui::Begin("Tests: Matrix Operators");
        ImGui::Text("matrixA * vectorA = ");
        Vec4f matAMultVecA = matrixA * vectorA;
        ImGuiCG1::DragVec4f("matrixA * vectorA", &matAMultVecA.x);
        ImGui::Separator();
        ImGui::NewLine();
        ImGui::Separator();


        // matrixB * vectorB:
        ImGui::Text("matrixB * vectorB = ");
        Vec4f matBMultVecB = matrixB * vectorB;
        ImGuiCG1::DragVec4f("matrixB * vectorB", &matBMultVecB.x);
        ImGui::Separator();
        ImGui::NewLine();
        ImGui::Separator();

        // matrixA * matrixB:
        ImGui::Text("matrixA * matrixB = ");
        Mat4f matAMultMatB = matrixA * matrixB;
        ImGuiCG1::DragMat4f("matrixA * matrixB", matAMultMatB.data);
        ImGui::Separator();
        ImGui::NewLine();
        ImGui::Separator();

        // matrixB * matrixA:
        ImGui::Text("matrixB * matrixA = ");
        Mat4f matBMultMatA = matrixB * matrixA;
        ImGuiCG1::DragMat4f("matrixB * matrixA", matBMultMatA.data);
        ImGui::Separator();
        ImGui::End();
    }
}
