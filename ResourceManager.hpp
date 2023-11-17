#pragma once

#include "Resource.hpp"

class ResourceManager
{
public:
    // Konstruktor domyślny
    ResourceManager() : resource(new Resource()) {
        // Inicjalizacja zarządzanego zasobu
    }

    // Destruktor
    ~ResourceManager() {
        delete resource;
        // Zasób zostanie automatycznie zwolniony przy zniszczeniu ResourceManager
    }

    // Konstruktor kopiujący
    ResourceManager(const ResourceManager& other) : resource(new Resource(*(other.resource))) {
        // Inicjalizacja kopii zarządzanego zasobu
    }

    // Operator przypisania kopiujący
    ResourceManager& operator=(const ResourceManager& other) {
        if (this != &other) {
            // Unikaj samoprzypisania
            delete resource;
            resource = new Resource(*(other.resource)); // Przypisanie kopii zarządzanego zasobu
        }
        return *this;
    }

    // Konstruktor przenoszący
    ResourceManager(ResourceManager&& other) noexcept : resource(other.resource) {
        other.resource = nullptr; // Przeniesienie własności
    }

    // Operator przypisania przenoszący
    ResourceManager& operator=(ResourceManager&& other) noexcept {
        if (this != &other) {
            // Unikaj samoprzypisania
            delete resource;
            resource = other.resource;
            other.resource = nullptr; // Przeniesienie własności
        }
        return *this;
    }

    // Metoda get
    double get() const {
        // Delegowanie wywołania do metody get zasobu
        return resource->get();
    }

    // Getter dla zarządzanego zasobu
    Resource* getResource() const {
        return resource;
    }

private:
    Resource* resource;  // Zarządzany zasób
};
