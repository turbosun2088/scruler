package main;

import javafx.application.Application;
import javafx.event.EventHandler;
import javafx.fxml.FXMLLoader;
import javafx.scene.Scene;
import javafx.scene.input.KeyEvent;
import javafx.scene.layout.BorderPane;
import javafx.stage.Stage;
import javafx.stage.StageStyle;

public class Main extends Application {
    @Override
    public void start(Stage primaryStage) throws Exception{
        BorderPane root = (BorderPane)FXMLLoader.load(getClass().getResource("mainwin.fxml"));
        primaryStage.setTitle("Screen Ruler");
        Scene sc = new Scene(root, 30, 800);
        primaryStage.setScene(sc);
        primaryStage.initStyle(StageStyle.UNDECORATED);
        EventHandler handler = new DragWin(primaryStage);
        root.setStyle("-fx-background-color: #61cccd;-fx-opacity: 0.8");
        sc.setFill(null);
        sc.setOnMousePressed(handler);
        sc.setOnMouseDragged(handler);
        sc.setOnKeyPressed(new EventHandler<KeyEvent>() {
            @Override
            public void handle(KeyEvent event) {
                switch (event.getCode()) {
                    case G:
                        if (event.isShortcutDown()) {
                            primaryStage.setWidth(30);
                            primaryStage.setHeight(800);
                        } else {
                            primaryStage.setWidth(1200);
                            primaryStage.setHeight(30);
                        }
                        break;
                    case ESCAPE:
                        primaryStage.close();
                        break;
                    default:
                        break;
                }
            }
        });
        primaryStage.initStyle(StageStyle.TRANSPARENT);

        primaryStage.show();
    }


    public static void main(String[] args) {
        launch(args);
    }
}
