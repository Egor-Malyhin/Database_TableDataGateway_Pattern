#include "Menu.h"

void Menu::menu()
{
    Connection connection;
    ProductsGateaway gatewayStudent(connection);
    StoresGateaway gateawayStore(connection);
    OrdersGateaway gateawayOrder(connection);
    DeliveryGateaway gateawayDelivery(connection);
    UserAction userAction;

    int choice;
    while (true) {
        std::cout << "Menu:" << std::endl;
        std::cout << "1. View all Products" << std::endl;
        std::cout << "2. Find Product by Id" << std::endl;
        std::cout << "3. Insert Product" << std::endl;
        std::cout << "4. Update Product" << std::endl;
        std::cout << "5. Delete Product" << std::endl;
        std::cout << "6. View Stores" << std::endl;
        std::cout << "7. Find Store by Id" << std::endl;
        std::cout << "8. Insert Store" << std::endl;
        std::cout << "9. Update Store" << std::endl;
        std::cout << "10. Delete Store" << std::endl;
        std::cout << "11. View Orders" << std::endl;
        std::cout << "12. Find Order by Id" << std::endl;
        std::cout << "13. Insert Order" << std::endl;
        std::cout << "14. Update Order" << std::endl;
        std::cout << "15. Delete Order" << std::endl;
        std::cout << "16. View Delivery" << std::endl;
        std::cout << "17. Find Delivery by Id" << std::endl;
        std::cout << "18. Insert Delivery" << std::endl;
        std::cout << "19. Update Delivery" << std::endl;
        std::cout << "20. Delete Delivery" << std::endl;

        std::cout << "0. Exit" << std::endl;

        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            userAction.viewProduct(gatewayStudent);
            break;
        case 2:
            userAction.findProductById(gatewayStudent);
            break;
        case 3:
            userAction.insertProduct(gatewayStudent);
            break;
        case 4:
            userAction.updateProduct(gatewayStudent);
            break;
        case 5:
            userAction.deleteProduct(gatewayStudent, gateawayOrder);
            break;
        case 6:
            userAction.viewStore(gateawayStore);
            break;
        case 7:
            userAction.findStoreById(gateawayStore);
            break;
        case 8:
            userAction.insertStore(gateawayStore);
            break;
        case 9:
            userAction.updateStore(gateawayStore);
            break;
        case 10:
            userAction.deleteStore(gateawayStore, gateawayOrder);
            break;
        case 11:
            userAction.viewOrder(gateawayOrder, gateawayStore, gatewayStudent, gateawayDelivery);
            break;
        case 12:
            userAction.findOrderById(gateawayOrder, gateawayStore, gatewayStudent, gateawayDelivery);
            break;
        case 13:
            userAction.insertOrder(gateawayOrder, gateawayStore, gatewayStudent);
            break;
        case 14:
            userAction.updateOrder(gateawayOrder, gateawayStore, gatewayStudent);
            break;
        case 15:
            userAction.deleteOrder(gateawayOrder, gateawayDelivery);
            break;
        case 16:
            userAction.viewDelivery(gateawayDelivery, gateawayOrder);
            break;
        case 17:
            userAction.findDeliveryById(gateawayDelivery, gateawayOrder);
            break;
        case 18:
            userAction.insertDelivery(gateawayDelivery, gateawayOrder);
            break;
        case 19:
            userAction.updateDelivery(gateawayDelivery, gateawayOrder);
            break;
        case 20:
            userAction.deleteDelivery(gateawayDelivery);
            break;
        case 0:
            std::cout << "Exiting the program." << std::endl;
            return;
        default:
            std::cout << "Invalid choice. Please try again." << std::endl;
            break;
        }
    }
    return;
}
