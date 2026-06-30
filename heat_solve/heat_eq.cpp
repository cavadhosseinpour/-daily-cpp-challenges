#include <iostream>
#include <vector>
#include <iomanip>
#include <fstream>

int main() {
    // 1. Spatial Domain Parameters
    const int Nx = 50;                  // Rows (Y-axis grid points)
    const int Ny = 50;                  // Columns (X-axis grid points)
    const double L = 0.1;               // 10 cm plate
    const double dx = L / (Nx - 1);     
    
    // 2. Copper Material Properties & Explicit Timestepping
    const double alpha = 1.11e-4;       // Diffusivity (m^2/s)
    const double target_time = 600.0;   // 10 minutes runtime
    const double dt = 0.0009;           // Time step size (seconds)
    const double F = (alpha * dt) / (dx * dx); 
    
    long long total_steps = static_cast<long long>(target_time / dt);

    // 3. Flattened Vectors
    std::vector<double> T_current(Nx * Ny, 20.0);
    std::vector<double> T_next(Nx * Ny, 20.0);

    // 4. Chronological Solver Loop
    for (long long step = 0; step < total_steps; ++step) {
        
        // --- 4a. Enforce Constant Left Wall Boundary (100.0°C Furnace) ---
        for (int i = 0; i < Nx; ++i) {
            int left_edge_index = i * Ny + 0; 
            T_current[left_edge_index] = 100.0;
            T_next[left_edge_index]    = 100.0;
        }

        // --- 4b. Core Intermediary Compute Domain ---
        for (int i = 1; i < Nx - 1; ++i) {
            for (int j = 1; j < Ny - 1; ++j) {
                int center = i * Ny + j;
                int right  = i * Ny + (j + 1); 
                int left   = i * Ny + (j - 1); 
                int up     = (i - 1) * Ny + j; 
                int down   = (i + 1) * Ny + j; 

                T_next[center] = T_current[center] + F * (
                    T_current[right] + T_current[left] + 
                    T_current[up]    + T_current[down] - 4.0 * T_current[center]
                );
            }
        }

        // --- 4c. Adiabatic Boundary Conditions (Insulated Edges via Ghost Nodes) ---
        
        // Top Edge (i = 0, skipping corners): No heat flux upward -> up = down node
        for (int j = 1; j < Ny - 1; ++j) {
            int center = 0 * Ny + j;
            int down   = 1 * Ny + j;
            int left   = 0 * Ny + (j - 1);
            int right  = 0 * Ny + (j + 1);
            T_next[center] = T_current[center] + F * (T_current[right] + T_current[left] + 2.0 * T_current[down] - 4.0 * T_current[center]);
        }

        // Bottom Edge (i = Nx - 1, skipping corners): No heat flux downward -> down = up node
        for (int j = 1; j < Ny - 1; ++j) {
            int center = (Nx - 1) * Ny + j;
            int up     = (Nx - 2) * Ny + j;
            int left   = (Nx - 1) * Ny + (j - 1);
            int right  = (Nx - 1) * Ny + (j + 1);
            T_next[center] = T_current[center] + F * (T_current[right] + T_current[left] + 2.0 * T_current[up] - 4.0 * T_current[center]);
        }

        // Right Edge (j = Ny - 1, skipping corners): No heat flux rightward -> right = left node
        for (int i = 1; i < Nx - 1; ++i) {
            int center = i * Ny + (Ny - 1);
            int left   = i * Ny + (Ny - 2);
            int up     = (i - 1) * Ny + (Ny - 1);
            int down   = (i + 1) * Ny + (Ny - 1);
            T_next[center] = T_current[center] + F * (2.0 * T_current[left] + T_current[up] + T_current[down] - 4.0 * T_current[center]);
        }

        // Push temporary computations to master vector
        T_current = T_next;
    }

    // 5. Clean Structured Preview
    std::cout << "Simulation complete. Displaying 13x13 thermal preview map:\n\n";
    for (int i = 0; i < Nx; i += 4) {
        for (int j = 0; j < Ny; j += 4) {
            std::cout << std::fixed << std::setprecision(1) << std::setw(6) << T_current[i * Ny + j] << "° ";
        }
        std::cout << "\n";
    }
    
    // 6. Generate Data Collection CSV
    std::ofstream data_file("heat_results.csv");
    if (data_file.is_open()) {
        for (int i = 0; i < Nx; ++i) {
            for (int j = 0; j < Ny; ++j) {
                data_file << T_current[i * Ny + j];
                if (j < Ny - 1) data_file << ",";
            }
            data_file << "\n";
        }
        data_file.close();
        std::cout << "\nSuccess: Corrected data saved to 'heat_results.csv'!" << std::endl;
    }

    return 0;
}
