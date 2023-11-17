#pragma once

#include "Resource.hpp"

class ResourceManager
{
public:
    // Konstruktor domyślny
    ResourceManager() : resource() {
        // Inicjalizacja zarządzanego zasobu
    }

    // Destruktor
    ~ResourceManager() {
        // Zasób zostanie automatycznie zwolniony przy zniszczeniu ResourceManager
    }

    // Konstruktor kopiujący
    ResourceManager(const ResourceManager& other) : resource(other.resource) {
        // Inicjalizacja kopii zarządzanego zasobu
    }

    // Operator przypisania kopiujący
    ResourceManager& operator=(const ResourceManager& other) {
        if (this != &other) {
            // Unikaj samoprzypisania
            resource = other.resource; // Przypisanie kopii zarządzanego zasobu
        }
        return *this;
    }

    // Konstruktor przenoszący
    ResourceManager(ResourceManager&& other) noexcept : resource(std::move(other.resource)) {
        // Inicjalizacja przeniesienia zarządzanego zasobu
    }

    // Operator przypisania przenoszący
    ResourceManager& operator=(ResourceManager&& other) noexcept {
        if (this != &other) {
            // Unikaj samoprzypisania
            resource = std::move(other.resource); // Przypisanie przeniesienia zarządzanego zasobu
        }
        return *this;
    }

    // Metoda get
    double get() const {
        // Delegowanie wywołania do metody get zasobu
        return resource.get();
    }

    // Getter dla zarządzanego zasobu
    Resource& getResource() {
        return resource;
    }

private:
    Resource resource;  // Zarządzany zasób
};
