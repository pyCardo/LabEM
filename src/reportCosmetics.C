#include <TCanvas.h>
#include <TFile.h>
#include <TH1.h>
#include <TGraph.h>
#include <TPad.h>
#include <iostream>

// THIS FUN CREATES THE 2x2 CANVAS
void reportCosmetics() {
    // Open the four ROOT files
    TFile *file1 = TFile::Open("build/root/cParticleTypes.root");
    TFile *file2 = TFile::Open("build/root/cImpulse.root");
    TFile *file3 = TFile::Open("build/root/cTheta.root");
    TFile *file4 = TFile::Open("build/root/cPhi.root");

    // Check if files opened successfully
    if (!file1 || !file2 || !file3 || !file4) {
        std::cerr << "Error opening one or more ROOT files!" << std::endl;
        return;
    }

    // Get the canvases from each ROOT file
    TCanvas *canvas1 = (TCanvas*)file1->Get("cParticleTypes");
    TCanvas *canvas2 = (TCanvas*)file2->Get("cImpulse");
    TCanvas *canvas3 = (TCanvas*)file3->Get("cTheta");
    TCanvas *canvas4 = (TCanvas*)file4->Get("cPhi");

    // Check if canvases were found
    if (!canvas1 || !canvas2 || !canvas3 || !canvas4) {
        std::cerr << "Error: One or more canvases not found!" << std::endl;
        return;
    }

    // Create a new canvas to hold all four canvases
    TCanvas *combinedCanvas = new TCanvas("types_pulse_theta_phi", "types_pulse_theta_phi", 800, 800);
    
    // Divide the canvas into 2x2 pads
    combinedCanvas->Divide(2, 2);

    // Function to draw the primitives from the original canvas
    auto drawPrimitivesFromCanvas = [](TCanvas *canvas, TCanvas *combinedCanvas, int padIndex) {
        combinedCanvas->cd(padIndex);  // Go to the specific pad
        TList *primitives = canvas->GetListOfPrimitives();  // Get the list of primitives
        if (!primitives) {
            std::cerr << "No primitives found in canvas!" << std::endl;
            return;
        }

        // Loop over all primitives and draw them
        for (int i = 0; i < primitives->GetSize(); i++) {
            TObject *obj = primitives->At(i);
            if (obj) {
                std::cout << "Drawing object of type: " << obj->ClassName() << std::endl;
                obj->Draw();  // Draw the object
            }
        }
    };

    // Draw primitives from each original canvas
    drawPrimitivesFromCanvas(canvas1, combinedCanvas, 1);  // Draw from canvas1 into pad 1
    drawPrimitivesFromCanvas(canvas2, combinedCanvas, 2);  // Draw from canvas2 into pad 2
    drawPrimitivesFromCanvas(canvas3, combinedCanvas, 3);  // Draw from canvas3 into pad 3
    drawPrimitivesFromCanvas(canvas4, combinedCanvas, 4);  // Draw from canvas4 into pad 4

    // Update the combined canvas to display the result
    combinedCanvas->Update();
// }

// THIS FUN CREATES THE 3x1 CANVAS
// void reportCosmetics() {
//     // Open the four ROOT files
//     TFile *file1 = TFile::Open("build/root/cInvMassDecayProd.root");
//     TFile *file3 = TFile::Open("build/root/cInvMassSubAll.root");
//     TFile *file2 = TFile::Open("build/root/cInvMassSubPiK.root");

//     // Check if files opened successfully
//     if (!file1 || !file2 || !file3) {
//         std::cerr << "Error opening one or more ROOT files!" << std::endl;
//         return;
//     }

//     // Get the canvases from each ROOT file
//     TCanvas *canvas1 = (TCanvas*)file1->Get("cInvMassDecayProd");
//     TCanvas *canvas3 = (TCanvas*)file3->Get("cInvMassSubAll");
//     TCanvas *canvas2 = (TCanvas*)file2->Get("cInvMassSubPiK");

//     // Check if canvases were found
//     if (!canvas1 || !canvas2 || !canvas3) {
//         std::cerr << "Error: One or more canvases not found!" << std::endl;
//         return;
//     }

//     // Create a new canvas to hold all four canvases
//     TCanvas *combinedCanvas = new TCanvas("inv_mass", "Invariant Mass", 800, 1200);  // Adjust the size to fit vertically
    
//     // Divide the canvas into 3 rows (one column) for the first 3 canvases
//     combinedCanvas->Divide(1, 3);

//     // Function to draw the primitives from the original canvas
//     auto drawPrimitivesFromCanvas = [](TCanvas *canvas, TCanvas *combinedCanvas, int padIndex) {
//         combinedCanvas->cd(padIndex);  // Go to the specific pad
//         TList *primitives = canvas->GetListOfPrimitives();  // Get the list of primitives
//         if (!primitives) {
//             std::cerr << "No primitives found in canvas!" << std::endl;
//             return;
//         }

//         // Loop over all primitives and draw them
//         for (int i = 0; i < primitives->GetSize(); i++) {
//             TObject *obj = primitives->At(i);
//             if (obj) {
//                 std::cout << "Drawing object of type: " << obj->ClassName() << std::endl;
//                 obj->Draw();  // Draw the object
//             }
//         }
//     };

//     // Draw primitives from each original canvas
//     drawPrimitivesFromCanvas(canvas1, combinedCanvas, 1);  // Draw from canvas1 into pad 1
//     drawPrimitivesFromCanvas(canvas2, combinedCanvas, 2);  // Draw from canvas2 into pad 2
//     drawPrimitivesFromCanvas(canvas3, combinedCanvas, 3);  // Draw from canvas3 into pad 3

//     // Update the combined canvas to display the result
//     combinedCanvas->Update();
}
